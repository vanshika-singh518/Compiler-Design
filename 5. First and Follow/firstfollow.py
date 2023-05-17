import sys
sys.setrecursionlimit(60)

def first(string):
    # print(string)
    first_ = set()
    if string in non_terminals:
        alternatives = productions_dict[string]

        for alternative in alternatives:
            first_2 = first(alternative)
            first_ = first_ | first_2

    elif string in terminals:
        first_ = {string}

    elif string == '' or string == '€':
        first_ = {'€'}

    else:
        first_2 = first(string[0])
        
        first_ = first_ | first_2

    return first_


def follow(nT):
    follow_ = set()
    prods = productions_dict.items()

    if nT == starting_symbol:
        follow_ = follow_ | {'$'}
    for nt, rhs in prods:
        for alt in rhs:
            for char in alt:
                if char == nT:
                    following_str = alt[alt.index(char) + 1:]
                    if following_str == '':
                        if nt == nT:
                            continue
                        else:
                            follow_ = follow_ | follow(nt)
                    else:
                        follow_2 = first(following_str)
                        if '€' in follow_2:
                            follow_ = follow_ | follow_2 - {'€'}
                            follow_ = follow_ | follow(nt)
                        else:
                            follow_ = follow_ | follow_2
    return follow_


terminals = ['(', ')', 'a', ',', '#']
non_terminals = ['S', 'L', 'R']
starting_symbol = 'S'

productions_dict = {
    'S': ['(L)', 'a'],
    'L': ['SR'],
    'R': [',SR', '']
}

FIRST = {}
FOLLOW = {}

for non_terminal in non_terminals:
    FIRST[non_terminal] = set()

for non_terminal in non_terminals:
    FOLLOW[non_terminal] = set()

for non_terminal in non_terminals:
    FIRST[non_terminal] = FIRST[non_terminal] | first(non_terminal)

FOLLOW[starting_symbol] = FOLLOW[starting_symbol] | {'$'}
for non_terminal in non_terminals:
    FOLLOW[non_terminal] = FOLLOW[non_terminal] | follow(non_terminal)

print("{: ^20}{: ^20}{: ^20}".format('Non Terminals', 'First', 'Follow'))
for non_terminal in non_terminals:
    print("{: ^20}{: ^20}{: ^20}".format(non_terminal, str(FIRST[non_terminal]), str(FOLLOW[non_terminal])))
