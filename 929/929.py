#MIT License
#Copyright (c) 2018 yangyuan
import sys
class Solution:
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        uniqueEmails = set()
        for email in emails:
            plusIndex = -1
            tmp = ""
            i   = 0
            j   = 0
            for c in email:
                if c == "@":
                    j = i
                    break
                elif c == "." :
                    if plusIndex == -1:#未遇到过'+'
                        tmp += email[j:i]
                        j = i + 1
                elif c == "+":
                    if plusIndex == -1:#只处理遇到的第一个'+',因为剩下的直到'@'的字符会被忽略
                        plusIndex = i
                        tmp += email[j:plusIndex]
                i += 1
            tmp += email[j:]
            uniqueEmails.add(tmp)
        return len(uniqueEmails)

s = Solution()
emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
s.numUniqueEmails(emails)
