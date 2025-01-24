class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if(n < 2){
            return n;
        }
        vector<char> ans;
        int i = 0;
        int j = i;

        while(i < n) {

            while(j < n && chars[i] == chars[j]){
                j++;
            }
            
            ans.push_back(chars[i]); 

            int len = j - i;

            if(len > 1){
                string num = to_string(len);
                for (char c : num) {
                    ans.push_back(c);
                }
            }

            i = j;
        }

        chars = ans;
        
        return ans.size();
    }
};