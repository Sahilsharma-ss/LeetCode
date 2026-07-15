# Three lines & 1 Line Code c++ Beats💯


# Approach 1
1. Calculate first n even no's Sum
2. Calculte first n odd no's Sum
3. return gcd of both 

# Complexity
- Time complexity:
O(log n)

- Space complexity:
O(1)

# Approach 2
1. Return n

# Complexity
- Time complexity:
O(1)

- Space complexity:
O(1)
# Code
```cpp []
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = pow(n,2);
        int even = n*(n+1);
        return std :: gcd(odd,even);
    }
};
```

```cpp []
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
       return n
    }
};
```