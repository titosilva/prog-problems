from typing import List

def read_lines() -> List[str]:
    lines = []

    while True:
        line = input()

        if len(line) == 0:
            return lines
        
        lines.append(line)

def exec_move(current_pos: List[int], move: str):
    moves = {
        'D': [0, 1],
        'U': [0, -1],
        'L': [-1, 0],
        'R': [1, 0],
    }

    if move not in moves:
        raise KeyError()

    current_pos[0] += moves[move][0]
    current_pos[1] += moves[move][1]

    current_pos[0] = max(current_pos[0], 0)
    current_pos[1] = max(current_pos[1], 0)
    current_pos[0] = min(current_pos[0], 2)
    current_pos[1] = min(current_pos[1], 2)

lines = read_lines()

keypad = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
]

keys = []

position = [1, 1]
total = 0
for line in lines:
    cnt = 0
    for move in line:
        exec_move(position, move)
        cnt += 1
        print(f'Move: {move}, new position: {position}')
    print(f'Executed {cnt} moves')
    print(f'Final position: {position}')
    print('----')
    keys.append(keypad[position[1]][position[0]])
    total += cnt

print(f'Total of moves: {total}')
print(keys)
