class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        n = len(s)
        k = len(words)
        word_length = len(words[0])
        substring_size = word_length * k
        word_count = collections.Counter(words)
        
        def check(i):
            # Copy the original dictionary to use for this index
            remaining = word_count.copy()
            words_used = 0
            
            # Each iteration will check for a match in words
            for j in range(i, i + substring_size, word_length):
                sub = s[j : j + word_length]
                if remaining[sub] > 0:
                    remaining[sub] -= 1
                    words_used += 1
                else:
                    break
            
            # Valid if we used all the words
            return words_used == k
        
        answer = []
        for i in range(n - substring_size + 1):
            if check(i):
                answer.append(i)

        return answer