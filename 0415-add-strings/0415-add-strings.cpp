class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = stoi(num1);
        int n2 = stoi(num2);
        int sum = n1+n2;
        return to_string(sum);
    }
};