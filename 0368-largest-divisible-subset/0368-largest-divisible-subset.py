class Solution:
    def largestDivisibleSubset(self, a: List[int]) -> List[int]:
        d = {1:[]}
        for q in sorted(a):
            d[q] = max((d[p] for p in d if q%p==0), key=len) + [q]
        
        return max(d.values(), key=len)