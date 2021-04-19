import math

def CM(x, a, b):
    lcm = a * b // math.gcd(a, b)
    return x//a + x//b - x//lcm
    
class Solution:
    def MN(self, n: int, a: int, b: int) -> int:
        lo, hi = 1, min(a, b) * n
        while lo < hi:
            mid = (lo + hi) >> 1
            if CM(mid, a, b) < n:
                lo = mid + 1
            else:
                hi = mid
                
        return hi % (10**9 + 7)
