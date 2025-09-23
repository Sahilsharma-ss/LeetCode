class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;
        int size1 = version1.size();
        int size2 = version2.size();
        int maxi = max(size1, size2);

        while (i < size1 || j < size2) {
            string str1 = "";
            string str2 = "";
            while (i < size1 && version1[i] == '0') i++;
            while (i < size1 && version1[i] != '.') {
                str1 += version1[i];
                i++;
            }
            while (j < size2 && version2[j] == '0') j++;
            while (j < size2 && version2[j] != '.') {
                str2 += version2[j];
                j++;
            }
            if (str1.empty()) str1 = "0";
            if (str2.empty()) str2 = "0";

            int no1 = stoi(str1);
            int no2 = stoi(str2);

            if (no1 < no2) return -1;
            if (no1 > no2) return 1;

            i++;
            j++;
        }
        return 0;
    }
};
