class Solution {
public:
    string removeStars(string& s) {
        
        size_t pos = 0;
        for (auto c : s) {
            if (c == '*') {
                --pos;                
            } else {
                s[pos++] = c;                               
            }
        }
        s.resize(pos);
        return s;
    }
};