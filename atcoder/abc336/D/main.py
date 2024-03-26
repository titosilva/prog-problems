def is_good_int(k: int) -> bool:
    x = k

    s = 0
    while x > 0:
        s += x % 10
        x //= 10

    return k % s == 0

if __name__ == "__main__":
    n = int(input())

    for i in range(1,n+1):
        if is_good_int(i):
            print(i)