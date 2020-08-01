class Solution:
    def validUtf8(self, data: [int]) -> bool:
        l = len(data)
        if l == 0:
            return False
        current = 0
        while current < l:
            byte_size = 0
            byte_valid = 0x80
            while byte_valid > 0:
                if data[current] & byte_valid == byte_valid:
                    byte_size += 1
                    byte_valid = byte_valid >> 1
                else:
                    break
            if byte_size == 1 or byte_size >= 5:
                return False
            if current + byte_size > l:
                return False
            if byte_size != 0:
                valid = 0x80
                for i in range(current + 1, current + byte_size):
                    if data[i] & valid != valid:
                        return False
                current += byte_size
            else:
                current += 1
        return True


if __name__ == "__main__":
    s = Solution()
    print(bin(250), bin(145))
    print(s.validUtf8([250, 145, 145, 145, 145]))
