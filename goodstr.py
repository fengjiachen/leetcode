import sys
if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())
    dic = {}
    m = 0
    for _ in range(n):
        temp = [0]*26
        line1 = sys.stdin.readline().strip()
        for c in line1:
            temp[ord(c)-ord('a')] += 1
        key = '#'.join(list(map(str, temp)))
        if key in dic:
            dic[key] += 1
        else:
            dic[key] = 1
        m = max(dic[key], m)
    print(m)
