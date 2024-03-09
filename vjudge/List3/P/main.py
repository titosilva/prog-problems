import string
digs = string.digits + string.ascii_letters

def int2base(x, base):
    if x < 0:
        sign = -1
    elif x == 0:
        return digs[0]
    else:
        sign = 1

    x *= sign
    digits = []

    while x:
        digits.append(digs[int(x % base)])
        x = int(x / base)

    if sign < 0:
        digits.append('-')

    digits.reverse()

    return ''.join(digits)

def op_a(num1: str, num2: str) -> str:
    n1 = num1.replace('V', '0')
    n1 = n1.replace('U', '1')
    n1 = n1.replace('C', '2')
    n1 = n1.replace('D', '3')

    n2 = num2.replace('V', '0')
    n2 = n2.replace('U', '1')
    n2 = n2.replace('C', '2')
    n2 = n2.replace('D', '3')


    s = str(int2base((i1 + i2), 4))
    s = s.replace('0', 'V')
    s = s.replace('1', 'U')
    s = s.replace('2', 'C')
    s = s.replace('3', 'D')

    return s

print(op_a('VUCDV', 'VUCDV'))

# n = input()
# for i in range(0, n):
#     num1 = input()
#     num2 = input()
    
#     for j in range(0, 3):
#         op = input()

#     r = input()