class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for(int i=0;i<s.size();i++)
        {
            if(isalpha(s[i]))
            {
                str+=tolower(s[i]);
            }
        }
        int i=0,j=str.size()-1;
        bool res=true;
        while(i<=j)
        {
            if(str[i]==str[j])
            {
                i++;
                j--;
            }
            else
            {
                res=false;
                break;
            }
        }
        return res;  
    }
};