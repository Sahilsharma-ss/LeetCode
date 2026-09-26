class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(auto i : knowledge)
        {
            mp[i[0]] = i[1];
        }
        string ans = "";
        int n = s.size();
        int i =0;
        while(i<n)
        {
            string str = "";
            bool flag = 0;
            int j = i+1;
            string key = "";
            if(s[i]=='(')
            {
                flag = 1;
                while(j<n && s[j]!=')')
                {
                    key += s[j];
                    j++;
                }
            }
            if(flag)
            {
                if(mp.find(key)!=mp.end())
                {
                    ans += mp[key];
                }
                else
                {
                    ans+='?';
                }
                i = j+1;
            }
            else
            {
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
};