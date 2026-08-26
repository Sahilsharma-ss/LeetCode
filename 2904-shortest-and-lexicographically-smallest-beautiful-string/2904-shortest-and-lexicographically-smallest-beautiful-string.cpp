class Solution {
public:
    bool check(int i,int j,string &s,int k)
    {
        int one =0;
        for(int st = i;st<=j;st++)
        {
            if(s[st]=='1')
            {
                one++;
            }
        }
        return one==k;
    }
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        vector<string>vec;
        for(int i =0;i<n;i++)
        {
            for(int j = i;j<n;j++)
            {
                if(check(i,j,s,k))
                {
                    vec.push_back(s.substr(i,j-i+1));
                }
            }
        }
        // for(auto i : vec)
        // {
        //     cout<<i<<" ";
        // }
        if(vec.size()==0) return "";
        sort(vec.begin(),vec.end(),[&](auto &a,auto &b)
        {
            if(a.size()==b.size())
            {
                return a<b;
            }
            return a.size()<b.size();
        });
        return vec[0];
    }
};