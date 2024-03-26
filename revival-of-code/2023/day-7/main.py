from collections import defaultdict
from typing import List

def detect_abba(s: str) -> bool:
    if len(s) < 4:
        return False
    
    i = 0
    while i <= len(s) - 4:
        # print(s[i], s[i+1])
        # print(s[i:i+2], s[i+4:i+2:-1])
        if s[i] != s[i+1] and s[i:i+2] == s[i+3:i+1:-1]:
            return True
        
        i += 1
        
    return False

def read_lines() -> List[str]:
    lines = []

    while True:
        line = input()

        if len(line) == 0:
            return lines
        
        lines.append(line)

lines = read_lines()

count = 0
for line in lines:
    parts = line.replace(']', '[').split('[')

    has_odd_abba = False
    has_even_abba = False
    for i in range(len(parts)):
        if i % 2 == 0 and has_even_abba:
            continue

        if i % 2 != 0 and has_odd_abba:
            continue

        has_abba = detect_abba(parts[i])
        # print(parts[i] + ':' + str(has_abba) + ":" + str(i))

        if not has_abba:
            continue

        if i % 2 == 0:
            has_even_abba = True
        else:
            has_odd_abba = True

    # print(has_odd_abba, has_even_abba)
    if has_even_abba and not has_odd_abba:
        count += 1

print(count)

