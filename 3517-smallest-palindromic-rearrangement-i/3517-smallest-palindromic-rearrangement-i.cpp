class Solution {
public:
    string smallestPalindrome(string s) {
        unordered_map<int,int>mp;
        for(auto i : s)
        {
            mp[i]++;
        }
        string str = "";
        char odd = '#';
        for(int i='a';i<='z';i++)
        {
            int cnt  = mp[i];
            if(cnt==0) continue;
            if(cnt%2)
            {
                odd = i;
            }
            for(int j = 0;j<cnt/2;j++)
            {
                str+=i;
            }
        }
        string rev =str;
        reverse(rev.begin(),rev.end());
        if(odd != '#') str += odd;
        str +=rev;
        return str;
    }
};