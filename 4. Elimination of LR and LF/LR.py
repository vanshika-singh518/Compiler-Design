def left_factor(grammar):
    non_terminals = set()
    factorized_rules = {}

    for rule in grammar:
        non_terminal, productions = rule.split('->')
        non_terminals.add(non_terminal)

        productions = productions.split('|')
        common_prefix = longest_common_prefix(productions)

        if common_prefix:
            if non_terminal not in factorized_rules:
                factorized_rules[non_terminal] = []

            factorized_productions = [production[len(common_prefix):] for production in productions if production.startswith(common_prefix)]
            factorized_rules[non_terminal].append(common_prefix + non_terminal + "'")
            factorized_rules[non_terminal + "'"] = factorized_productions

        else:
            if non_terminal not in factorized_rules:
                factorized_rules[non_terminal] = []

            factorized_rules[non_terminal].extend(productions)

    return factorized_rules


def longest_common_prefix(strings):
    if not strings:
        return ''

    prefix = strings[0]

    for string in strings[1:]:
        while not string.startswith(prefix):
            prefix = prefix[:-1]

    return prefix


# Example usage
grammar = [
    'S->abc|abx|aby',
    'A->abAB|abA|ab',
    'B->bB|b',
]

factorized_grammar = left_factor(grammar)

print("Factorized Grammar:")
for non_terminal, productions in factorized_grammar.items():
    print(f"{non_terminal}->{'|'.join(prod if prod != '' else '#' for prod in productions)}")

# Output

# Factorized Grammar:
# S->abS'
# S'->c|x|y
# A->abA'
# A'->AB|A|#
# B->bB'
# B'->B|#
