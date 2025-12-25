class Solution {
public:
    string maskPII(string s) {
        // EMAIL CASE
        if (s.find('@') != string::npos) {
            for (char &c : s)
                c = tolower((unsigned char)c);

            int at = s.find('@');
            string name = s.substr(0, at);
            string domain = s.substr(at);

            return string(1, name[0]) + "*****" +
                   string(1, name.back()) + domain;
        }

        // PHONE CASE
        string digits;
        for (char c : s) {
            if (isdigit((unsigned char)c))
                digits.push_back(c);
        }

        int n = digits.size();
        string last4 = digits.substr(n - 4);

        string res;
        int country = n - 10;

        if (country > 0) {
            res += '+';
            res += string(country, '*');
            res += '-';
        }

        res += "***-***-" + last4;
        return res;
    }
};
