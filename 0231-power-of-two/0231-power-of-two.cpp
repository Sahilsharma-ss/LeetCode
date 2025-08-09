class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        if(n>0&&n &(n-1))
        {
            return false;
        }
        else return true;
    }
};