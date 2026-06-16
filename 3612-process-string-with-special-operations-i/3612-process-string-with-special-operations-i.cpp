class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(auto i :s)
        {
            if(isalpha(i))
            {
                res+=i;
            }
            else if(i=='*')
            {
                // if(res.size()==1)
                // {
                //     res = "";
                //     continue;
                // }
                string str = res.substr(0,res.size()-1);
                res = str;
            }
            else if(i=='#')
            {
                res += res;
            }
            else if(i=='%')
            {
                string str = res;
                reverse(str.begin(),str.end());
                res = str;
            }
        }
        return res;
    }
};