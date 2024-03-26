from typing import List

def read_lines() -> List[str]:
    lines = []

    while True:
        line = input()

        if len(line) == 0:
            return lines
        
        lines.append(line)

lines = read_lines()

count = 0
tested = 0
for line in lines:
    sides = [int(s) for s in line.split()]
    
    possible = True
    for i in range(4):
        if sides[i % 3] + sides[(i + 1) % 3] <= sides[(i + 2) % 3]:
            print(f'Impossible: {line}')
            possible = False
            break

    if possible:
        count += 1

    tested += 1

print(f'Tested {tested} triangles')
print(f'Found {count} possible triangles')