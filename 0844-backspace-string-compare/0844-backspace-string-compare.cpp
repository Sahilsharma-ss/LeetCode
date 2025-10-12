class Solution {
public:
    void update(string &s)
    {
        int n=s.size()-1;
        int cnt=0;
        while(n>=0)
        {
            if(s[n] == '#')
            {
                cnt++;
            }
            bool ok =false;
            while(cnt>0 &&n >= 0&& s[n]!='#')
            {
                s[n] = '#';
                cnt--;
                n--;
                ok=true;
            }
            if(!ok) n--;
        }
        string tmp = "";
        for (char c : s)
        {
            if (c != '#') tmp.push_back(c);
        }
        s = tmp;
    }
    bool backspaceCompare(string s, string t) {
        int n=s.size()-1;
        update(s);
        update(t);
        cout<<s;
        cout<<t;
        return s==t;
    }
};