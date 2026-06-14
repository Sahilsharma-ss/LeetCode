class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            unordered_map<int, int> cnt;

            for (int j = i; j < n; j++) {
                int x = nums[j];
                int old = freq[x];

                if (old) {
                    cnt[old]--;
                    if (cnt[old] == 0)
                        cnt.erase(old);
                }

                freq[x]++;
                cnt[old + 1]++;

                bool ok = false;

                if (freq.size() == 1)
                    ok = true;
                else if (cnt.size() == 2) {
                    auto it = cnt.begin();

                    int f1 = it->first;
                    ++it;
                    int f2 = it->first;

                    if (max(f1, f2) == 2 * min(f1, f2))
                        ok = true;
                }

                if (ok)
                    ans = max(ans, j - i + 1);
            }
        
        }
         return ans;
    }
};