#include <string>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string str = to_string(num);
        string str2 = to_string(num);
        int i = 0;
        while (i < str.size() && str[i] == '9') {
            i++;
        }

        if (i < str.size()) {
            char n = str[i];
            for (int j = 0; j < str.size(); j++) {
                if (str[j] == n) {
                    str[j] = '9';
                }
            }
        }

        int no = stoi(str);
        i = 0;
        while (i < str2.size() && str2[i] == '0') {
            i++;
        }

        if (i < str2.size()) {
            char n1 = str2[i];
            for (int j = 0; j < str2.size(); j++) {
                if (str2[j] == n1) {
                    str2[j] = '0';
                }
            }
        }

        int no1 = stoi(str2);

        return no - no1;
    }
};
