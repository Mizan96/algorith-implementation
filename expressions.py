grammar = ['id','E*E', 'E+E', 'E-E']
base = 'E'
# 'id*id+id-id*id'
exp = input('Enter an expression:\n')
exp_list = list(exp)
stack = []
for x in exp_list:
    if x is '+' or  x is '-' or  x is '*':
        stack.append(x)

start = []
start.append(base)
print('Parsing stars:')
print(''.join(start))
stack_len = len(stack)
while stack_len > 0:
    operator = stack.pop()
    for x in grammar:
        if operator in list(x):
            start.pop()
            for y in list(x):
                start.append(y)
    print(''.join(start[::-1]))
    start[len(start)-3]=grammar[0]
    print(''.join(start[::-1]))
    stack_len -= 1
start[len(start)-1]=grammar[0]
print(''.join(start[::-1]))

