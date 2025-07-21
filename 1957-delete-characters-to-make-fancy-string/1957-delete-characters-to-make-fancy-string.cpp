class Solution {
public:
    string makeFancyString(string s) {
        for (int i = 2; i < s.size(); i++) {
            int a = s[i - 2];
            int b = s[i - 1];
            int c = s[i];
            if (a == b && b == c) {
                int temp=i+1;
                while (s[temp] == c) {
                    temp++;
                }
                s.erase(i, temp-i);
            }
        }
         return s;
    }
};