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

def find_match(x, y):
    for src in range(2, 37):
        for dst in range(2, 37):
            try:
                v = int(x, int(src))
            except:
                continue

            r = int2base(v, int(dst)).upper()

            if r == y:
                print(f"{x} (base {src}) = {y} (base {dst})")
                return
            
    print(f"{x} is not equal to {y} in any base 2..36")

for line in sys.stdin:
    x, y = line.split()
    find_match(x, y)