class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int j = 0;
        int n = chars.size();
        while (j < n)
        {
            char c = chars[j];
            int cnt = 0;
            while (j < n && chars[j] == c)
            {
                j++;
                cnt++;
            }
            chars[i] = c;
            i++;
            if (cnt > 1)
            {
                string num = to_string(cnt);
                for (char d : num)
                {
                    chars[i] = d;
                    i++;
                }
            }
        }
        return i;
    }
};
