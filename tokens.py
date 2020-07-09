f = open('code.txt', 'r')
x = f.read().splitlines()
special = [',','.','{','}','[',']','(',')','<','>','#']
space = [' ']
deli = [';']
operator = ['+','-','*','%','/','=']
key = ['include', 'stdio','int', 'float','scanf','printf']

def check(val):
    con = ''.join(val)
    if con.isnumeric():
        print('     ----> CONSTANT')
    elif con in special:
        print('     ----> SPECIAL CHARACTER')
    elif con in space:
        print('Space Removed')
    elif con in deli:
        print('     ----> DELIMITER')
    elif con in operator:
        print('     ----> OPERATOR')
    elif con in key:
        print('     ----> KEYWORD')
    else:
        print('     ----> IDENTIFIER')

counter = 1
for  a in x:
    print('Line = ',counter)
    print('______')
    counter += 1
    print('CONTENTS: ', ''.join(a))
    print('TOKENS:------')
    b = []
    l = len(a)
    a = list(a)
    for i in range(l):
        temp = a.pop(0)
        if temp.isnumeric() or temp in special or temp in space or temp in deli or temp in operator or temp in key:
            if len(b) > 0:
                print(''.join(b), end='')
                check(b)
                b=[]
                print(temp,end='')
                check(temp)  
            else:
                print(temp,end='')
                check(temp)
        else:
            b.append(temp)
        temp = []
    print('-----------------------------------------------------------------------------')

