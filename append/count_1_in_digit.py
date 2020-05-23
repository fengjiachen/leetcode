def count1(num):
    l = len(num)
    if l == 0:
        return 0
    first = int(num[0])
    if l == 1 and first == 0:
        return 0
    if l == 1 and first == 1:
        return 1
    num_in_first = 0
    if first > 1:
        num_in_first = int(10 ** (l - 1))
    elif first == 1:
        num_in_first = int(num[1:]) + 1

    num_in_other = (first) * (l - 1) * int(10 ** (l - 2))
    return num_in_first+num_in_other+count1(num[1:])


if __name__ == "__main__":
    print(count1('21345'))
