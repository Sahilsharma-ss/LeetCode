class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (auto i : ransomNote) {
            size_t pos = magazine.find(i);
            if (pos == std::string::npos) 
            {
                return false;
            }
            magazine[pos] = '-1';
        }
        return true;
    }
};

