# Given two strings s and t, determine if they are isomorphic.
#
# Two strings are isomorphic if the characters in s can be replaced to get t.
#
# All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
#
# Example 1:
#
# Input: s = "egg", t = "add"
# Output: true
# Example 2:
#
# Input: s = "foo", t = "bar"
# Output: false
# Example 3:
#
# Input: s = "paper", t = "title"
# Output: true


def isIsomorphic(s: str, t: str) -> bool:
    pos1, pos2 = [-1] * 256, [-1] * 256
    for i in range(len(s)):
        if pos1[ord(s[i])] != pos2[ord(t[i])]:
            return False
        pos1[ord(s[i])] = pos2[ord(t[i])] = i
    return True



def main():
    s = "paper"
    t = "title"
    print(isIsomorphic(s,t))


if __name__ == '__main__':
    main()
