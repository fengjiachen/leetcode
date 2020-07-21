import sys
if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())

    line1 = sys.stdin.readline().strip()
    roubst = list(map(int, line1.split()))
    line2 = sys.stdin.readline().strip()
    normal = list(map(int, line2.split()))
    add = zip(roubst, normal)
    new_add = sorted(add, reverse=True)
    for r, n in new_add:
        print(r, n)
