class Solution {
public:
    string reverseWords(string s) {
        vector<string>vec;
        int n=s.size();
        int i=0;
        while(i<n && s[i]==' ') i++;
        while(i<n)
        {
            while(i<n && s[i]==' ') i++;
            string str="";
            while(i<n&&s[i]!=' ')
            {
                str+=s[i];
                i++;
            }
            if(str.empty()) continue;
            vec.push_back(str);
        }
        string res="";
        for(int i=vec.size()-1;i>=0;i--)
        {
            res+=vec[i];
            if(i!=0)
            {
               res+=" "; 
            }
        }
        return res;
    }
};