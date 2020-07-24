
c = [0]*11
for i in range(1, 10):
    c[i] = c[i & (i-1)]+1
    print(i, bin(i), i-1, bin(i-1), i & (i-1), c[i])
