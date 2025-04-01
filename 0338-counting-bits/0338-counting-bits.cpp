class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0); 
        
        for (int i = 0; i <= n; i++) { 
            if (i == 0) {
                res[i] = 0; 
            } else if ((i & (i - 1)) == 0) { 
                res[i] = 1; 
            } else {
                res[i] = res[i & (i - 1)] + 1; 
            }
        }
        return res;
    }
};
