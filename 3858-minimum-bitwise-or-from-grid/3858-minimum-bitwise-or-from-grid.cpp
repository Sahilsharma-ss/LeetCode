class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int ans = 0;
        int forbidden = 0;  // bits we are trying to keep 0
        
        for (int bit = 31; bit >= 0; --bit) {
            int testForbidden = forbidden | (1 << bit);

            //forbidden -> all the previous larger bits which we've decided to keep 0
            // (1<<bit) -> the new bit which we're testing
            
            bool possible = true;

            for (auto &row : grid) {
                bool found = false;

                for (int num : row) {
                    // num must not contain any forbidden bit
                    if ((num & testForbidden) == 0) {
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                forbidden = testForbidden;   // we can keep this bit 0
            } else {
                ans |= (1 << bit);           // must set this bit
            }
        }

        return ans;
    }
};