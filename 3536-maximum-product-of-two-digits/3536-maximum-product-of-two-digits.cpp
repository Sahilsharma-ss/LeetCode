class Solution {
public:
    int maxProduct(int n) {
        int ans = 0;
        int maxi = -1e9;
        int secm = -1e9;
        vector<int>vec;
        while(n>0)
        {
            int rem = n%10;
            vec.push_back(rem);
            n/=10;
        }
        sort(vec.begin(),vec.end(),greater<int>());
        return (vec[0]*vec[1]);
    }
};