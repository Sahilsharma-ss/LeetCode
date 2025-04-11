#include<bits/stdc++.h>
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++)
        {
            string s=to_string(i);
            if(s.size()%2!=0) continue;
            int n=s.size()/2;
            int s1=0,s2=0;
            for(int i=0;i<s.size();i++)
            {
                int no =s[i]-'0';
                if(i<n)
                {
                    s1+=no;
                }
                else
                {
                    s2+=no;
                }
            }
            if(s1==s2) cnt++;
        }
        return cnt;
    }
};