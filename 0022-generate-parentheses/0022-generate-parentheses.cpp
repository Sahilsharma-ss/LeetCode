class Solution {
public:
    void gp(int open,int close,int n,string temp,vector<string>&res)
    {
        if(temp.size()==2*n)
        {
            res.push_back(temp);
            return;
        }
        if(open<n)
        {
            gp(open+1,close,n,temp+'(',res);
        }
        if(close<open)
        {
            gp(open,close+1,n,temp+')',res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string temp="";
        gp(0,0,n,temp,res);
        return res;
    }
};