class Solution {
public:
    vector<int>arr{1,3,7,15,31,63,127,255,511,1023};
    int smallestNumber(int n) {
        int up = lower_bound(arr.begin(),arr.end(),n) - arr.begin();
        return arr[up];
    }
};