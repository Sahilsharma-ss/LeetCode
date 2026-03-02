class Solution {
public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        if(n == 0) return 0;

        vector<int> inc(n), dec(n);
        inc[0] = arr[0];
        for(int i = 1; i < n; i++) {
            inc[i] = max(inc[i-1], arr[i]);
        }
        dec[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; i--) {
            dec[i] = max(dec[i+1], arr[i]);
        }
        int water = 0;
        for(int i = 0; i < n; i++) {
            water += min(inc[i], dec[i]) - arr[i];
        }

        return water;
    }
};