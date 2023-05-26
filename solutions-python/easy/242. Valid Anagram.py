class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        a = dict(zip([chr(x) for x in range(ord('a'),ord('z')+1)],[0]*26))
        b = dict(zip([chr(x) for x in range(ord('a'),ord('z')+1)],[0]*26))
        for c in s:
            a[c] = a[c] + 1
        for c in t:
            b[c] = b[c] + 1

        for c in range(ord('a'),ord('z')+1):
            if a[chr(c)] != b[chr(c)]:
                return False

        return True

# or

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        freq = dict(zip([chr(x) for x in range(ord('a'),ord('z')+1)],[0]*26))

        for c in s:
            freq[c] = freq[c] + 1
        for c in t:
            freq[c] = freq[c] - 1

        for c in range(ord('a'),ord('z')+1):
            if freq[chr(c)]!=0:
                return False

        return True
