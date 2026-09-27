class Solution {
public:
    string reverseParentheses(string s) {
        int cnt = 0;
        for(char i : s)
        {
            if(i=='(')
            {
                cnt++;
            }
        }
        if(cnt==0) return s;
        int mid = cnt;
        int l = 0;
        int n = s.size();
        int c = 0;
        while(l<n && c<mid)
        {
            if(s[l]=='(')
            {
                c++;
            }
            l++;
        }
        l--;
       // cout<<s[l];
        while(l>=0 && cnt)
        {
            string str = "";
            while(l>=0 && s[l]!='(')
            {
                l--;
            }
            int r = l+1;
            while( r<n && s[r]!=')')
            {
                str += s[r];
                r++;
            }
           // cout<<s[r];
            if(s[l]=='(' && s[r]==')')
            {   
                string newstr = "";
                if(l>0) newstr += s.substr(0,l);
                reverse(str.begin(),str.end());
                newstr += str;
                if(r<n) newstr += s.substr(r+1);
                s = newstr;
                cnt--;
            }
        }
        return s;
    }
};