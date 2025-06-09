class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> arr(pref.size());

        int x = 0;
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = x ^ pref[i];

            x ^= arr[i];
        }

        return arr;
    }
};