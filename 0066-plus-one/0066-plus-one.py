# class Solution:
#     def plusOne(self, digits: List[int]) -> List[int]:
#         for i in reversed(range(len(digits))):
#             if digits[i]!=9:
#                 digits[i]+=1
#                 return digits
#             digits[i]=0
#         return [1]+digits

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        for i in range(len(digits)-1, -1, -1):
            curr_digit = digits[i]
            digits[i] = 1 + curr_digit

            if curr_digit != 9: return digits
            else: digits[i] = 0
        
        return [1] + digits