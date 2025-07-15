class Solution {
public:
    bool isvowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
            ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' ||
            ch == 'U') {
            return true;
        }
        return false;
    }

    bool isValid(string word) {
        bool validflag = false;
        bool vowelflag = false;
        bool cons = false;
        bool notvalid = false;

        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];

            if ((ch >= '0' && ch <= '9') || 
                (ch >= 'a' && ch <= 'z') || 
                (ch >= 'A' && ch <= 'Z')) 
            {
                validflag = true;

                if (isvowel(ch)) {
                    vowelflag = true;
                }
                else if (!isvowel(ch) && 
                         ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')))
                {
                    cons = true;
                }
            }
            else {
                notvalid = true; 
            }
        }

        return word.size() >= 3 && validflag && vowelflag && cons && !notvalid;
    }
};
