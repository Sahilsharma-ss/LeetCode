class Solution {
public:
    string revinvert(string str)
    {
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='0')
            {
                str[i]='1';
            }
            else
            {
                str[i] = '0';
            }
        }
        reverse(str.begin(),str.end());
        return str;
    }
    char findKthBit(int n, int k) {
        string str = "0";
        string prev = "";
        n=n-1;
        while(n--)
        {
           string revin = revinvert(str);
           str+="1";
           str+=revin;
        //    cout<<str<<endl;
        }
        char ans = str[k-1];
        //cout<<str;
        return ans;
    }
};