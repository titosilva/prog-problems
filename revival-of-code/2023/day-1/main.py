from typing import Tuple

def rotate_dir(rot: str, current_dir: Tuple[int, int]) -> Tuple[int, int]:
    directions_clockwise = [
        (0, 1),
        (1, 0),
        (0, -1),
        (-1, 0),
    ]

    idx = directions_clockwise.index(current_dir)
    return directions_clockwise[(idx + 1) % 4 if rot == 'R' else (idx - 1) % 4]

moves = input().strip().replace(',', '').split()

position = [0, 0]
direction = (0, 1)

for move in moves:
    print(f'\nCurrent position: {position[0]}, {position[1]}')
    print(f'Current direction: {direction[0]}, {direction[1]}')
    print(f'Next move: {move}')
    direction = rotate_dir(move[0], direction)
    position[0] += int(move[1:]) * direction[0]
    position[1] += int(move[1:]) * direction[1]

print(f'\n\nFinal position: {position[0]}, {position[1]}')
print(f'Shortest path (L1): {abs(position[0]) + abs(position[1])}')
print(f'Moves executed: {len(moves)}')
