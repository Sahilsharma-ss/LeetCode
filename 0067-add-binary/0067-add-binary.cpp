class Solution {
public:
    string addBinary(string a, string b) {

        long long no1 = stoll(a, nullptr, 2);
        long long no2 = stoll(b, nullptr, 2);

        long long res = no1 + no2;

        string ans = bitset<64>(res).to_string();

        if(res == 0) return "0";

        return ans.substr(ans.find('1'));
    }
};
