import string
digs = string.digits + string.ascii_letters

def to_base(n, b):
    if n == 0:
        return [0]
    digits = []
    while n:
        digits.append(int(n % b))
        n //= b
    return digits[::-1]

def get_s(n, b):
    return sum(to_base(n, b))

for b in range(10, 100):
    print(f"{b}: {get_s(321, b)}")


