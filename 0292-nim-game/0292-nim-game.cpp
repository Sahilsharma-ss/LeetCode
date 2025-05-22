class Solution {
public:
    bool canWinNim(int n) {
       if(n<=3) return true;
        n=n%3;
        n=n/2;
        if(n%2==0) return false;
        return true;
    }
};