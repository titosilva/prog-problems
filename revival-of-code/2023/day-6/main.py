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

counts: List[defaultdict] = []
for i in range(len(lines[0])):
    counts.append(defaultdict(lambda: 0))

for line in lines:
    for i in range(len(line)):
        counts[i][line[i]] += 1

for count in counts:
    chars = count.keys()
    
    print(sorted(chars, key=lambda c: count[c], reverse=True)[0], end='')

print('')