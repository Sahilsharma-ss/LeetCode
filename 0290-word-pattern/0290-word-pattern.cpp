class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        int i = 0, pos = 0;
        for (char ch : pattern) {
            if (pos >= s.size()) return false;
            int start = pos;
            while (pos < s.size() && s[pos] != ' ') pos++;
            string word = s.substr(start, pos - start);
            pos++; 
            if (charToWord.count(ch) && charToWord[ch] != word) return false;
            if (wordToChar.count(word) && wordToChar[word] != ch) return false;
            charToWord[ch] = word;
            wordToChar[word] = ch;
        }
        return pos >= s.size();
    }
};
