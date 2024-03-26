from collections import defaultdict
from typing import List

def read_lines() -> List[str]:
    lines = []

    while True:
        line = input()

        if len(line) == 0:
            return lines
        
        lines.append(line)

lines = read_lines()

total = 0
for line in lines:
    counts = defaultdict(lambda: 0)
    sections = line.split('-')

    for section in sections[:-1]:
        for char in section:
            counts[char] += 1

    chars = counts.keys()
    s = sorted(chars, key=lambda c1: (counts[c1], -1 * ord(c1)), reverse=True)
    print(s)

    value, check = sections[-1].replace(']', '').split('[')

    ok = True
    for i in range(len(check)):
        if check[i] != s[i]:
            ok = False
            break

    if ok:
        total += int(value)

print(total)