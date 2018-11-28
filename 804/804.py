#MIT License
#Copyright (c) 2018 yangyuan
import sys

ORD_A     = 97
EMPTY_STR = ""
trans = [".-","-...","-.-.",
        "-..",".","..-.",
        "--.","....","..",
        ".---","-.-",".-..",
        "--","-.","---",
        ".--.","--.-",".-.",
        "...","-","..-",
        "...-",".--","-..-",
        "-.--","--.."]
class Solution:
    def uniqueMorseRepresentations(self, words):
        uniqueWords = set()
        for word in words:
            morseCodeList = []
            for c in word:
                morseCodeList.append(trans[ord(c) - ORD_A])
            tmpStr = EMPTY_STR.join(morseCodeList)
            if tmpStr not in uniqueWords:
                uniqueWords.add()
        return len(uniqueWords)

words = ["gin", "zen", "gig", "msg"]
slt = Solution()
count = slt.uniqueMorseRepresentations(words)
print(count)
