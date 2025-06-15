class Solution {
public:
    int maxDiff(int num) {
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
        //min
        if (str2[0] != '1') {
            char n1 = str2[0];
            for (int j = 0; j < str2.size(); j++) {
                if (str2[j] == n1) {
                    str2[j] = '1';
                }
            }
        } else {
            for (int k = 1; k < str2.size(); k++) {
                if (str2[k] != '0' && str2[k] != '1') {
                    char n2 = str2[k];
                    for (int j = 0; j < str2.size(); j++) {
                        if (str2[j] == n2) {
                            str2[j] = '0';
                        }
                    }
                    break;
                }
            }
        }

        int no1 = stoi(str2);
        return no - no1;
    }
};
