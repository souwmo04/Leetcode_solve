class Solution:
    def triangleType(self, nums: List[int]) -> str:
        a, b, c = nums[0], nums[1], nums[2]
        
        # Check for triangle inequality
        if a + b <= c or b + c <= a or c + a <= b:
            return "none"
        
        # Check for triangle type
        if a == b == c:
            return "equilateral"
        elif a == b or b == c or a == c:
            return "isosceles"
        else:
            return "scalene"
