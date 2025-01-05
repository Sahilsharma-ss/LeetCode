class Solution {
public:
    bool isPalindrome(int x) {
        int t=x;
        int rev =0;
        if(x>=0)
        {
        while(x!=0)
        {
            int r=x%10;
            if (rev > (INT_MAX - r) / 10) {
            return false; 
            }
            rev = rev *10 +r;
            x=x/10;
        }
        return (rev==t);
        }
        else
        {
            return false;
        }
    }
};