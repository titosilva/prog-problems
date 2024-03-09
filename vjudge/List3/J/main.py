import sys
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

for line in sys.stdin:
    src, dst, num = line.split()

    try:
        v = int(num, int(src))
    except:
        print(f'{num} is an illegal base {src} number')
        continue

    r = int2base(v, int(dst)).upper()

    print(f"{num} base {src} = {r} base {dst}")