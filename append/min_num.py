import functools


def com(a, b):
    ab = a + b
    ba = b + a
    if ab < ba:
        return - 1
    elif ab == ba:
        return 0
    else:
        return 1


def min_nun(nums):
    nums.sort(key=functools.cmp_to_key(com))
    print(nums)


if __name__ == "__main__":
    nums = ['3', '32', '321']
    min_nun(nums)
