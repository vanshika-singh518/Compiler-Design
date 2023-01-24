import re

keyword = ['break','case','char','const','class','countinue','default','do','int','else','enum','extern','main','float','for','goto','if','long','register','return','short','signed','sizeof','static','switch','typedef','union','unsigned','void','volatile','while']
built_in_functions = ['clrscr()','printf(','scanf(','getch()','main()']
operators = ['+','-','*','/','%','==','!=','>','<','>=','<=','&&','||','!','&','|','^','~','>>','<<','=','+=','-=','*=']
specialsymbol = ['@','#','$','_','!']
separator = [',',':',';','\n','\t','{','}','(',')','[',']']


file = open('prog.txt','r+')
contents = file.read()
splitCode = contents.split() #split program in word based on space
length = len(splitCode)      # count the number of word in program

kc = oc = ic = nc = 0
for i in range(0,length):
    if splitCode[i] in keyword:
        print(splitCode[i], ": Keyword")
        kc += 1
        continue
    if splitCode[i] in operators:
        print(splitCode[i], ": Operators")
        oc += 1
        continue
    if splitCode[i] in specialsymbol:
        print(splitCode[i], ": Special Operator")
        continue

    if splitCode[i] in separator:
        #print(splitCode[i], ":Separator")
        continue
    if re.match(r'^[-+]?[0-9]+$',splitCode[i]):
        print(splitCode[i], ": Number")
        nc += 1
        continue
    if re.match(r"^[^\d\W]\w*\Z", splitCode[i]):
        print(splitCode[i],":Identifier")
        ic += 1
    else:
        print(splitCode[i], ": Invalid Identifier")
        
print("\nKeyword count : ",kc)
print("Operator count : ",oc)
print("Identifier count : ",ic)
print("Number count : ",nc)
