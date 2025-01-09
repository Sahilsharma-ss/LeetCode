class Solution {
public:
    string toLowerCase(string s) {
        string res ="";
        for(auto i : s)
        {
            res +=tolower(i);
        }
        return res;
    }
};