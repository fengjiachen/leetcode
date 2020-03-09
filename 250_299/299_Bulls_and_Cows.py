def getHint(secret: str, guess: str) -> str:
    numa = 0
    dic = {}
    for i in range(len(secret)):
        if secret[i] == guess[i]:
            numa += 1
        else:
            if secret[i] in dic:
                dic[secret[i]] += 1
            else:
                dic[secret[i]] = 1
    numb = 0
    for i in range(len(secret)):
        if secret[i] != guess[i] and guess[i] in dic:
            dic[guess[i]] -= 1
            numb += 1
            if dic[guess[i]] == 0:
                dic.pop(guess[i])
    return '{}A{}B'.format(numa, numb)


print(getHint('1123', '0111'))
