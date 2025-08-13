class Solution {
public:
    bool isPowerOfThree(int n) {
        int i=0;
        set<int>s;
        while(pow(3,i)<=INT_MAX)
        {
            s.insert(pow(3,i));
            i++;
        }
        if(s.find(n)!=s.end())
        {
            return true;
        }
        return false;
    }
};