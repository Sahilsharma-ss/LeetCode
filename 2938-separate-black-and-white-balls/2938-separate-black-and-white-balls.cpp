class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
        long long ans=0;
        int cnt=0;
        int r=0;
        while(r<n)
        {
           if(s[r]=='1')
           {
            cnt++;
           }
           else if(s[r]=='0')
           {
            ans+=cnt;
           }
           r++;
        }
        return ans;
    }
};