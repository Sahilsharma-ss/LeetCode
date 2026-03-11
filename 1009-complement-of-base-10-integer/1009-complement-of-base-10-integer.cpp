class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        string s = bitset<32>(n).to_string();
        s = s.substr(s.find('1'));
       // cout<<s<<endl;
         string str = "";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
            {
                str+="1";
            }
            else
            {
                str+="0";
            }
        }
        //cout<<str<<endl;
       int no = stoi(str,nullptr,2);
        return no;
    }
};