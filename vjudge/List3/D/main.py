s = 0

for i in range(1, 50000):
    s += i ** 3
    # print(f"{i}: {s} = {(i * (i + 1) / 2) ** 2}, {s ** (0.5)} = {i * (i + 1) / 2}")
    print(s)