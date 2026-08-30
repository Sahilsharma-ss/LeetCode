class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        vector<pair<int,int>>vec;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end());
        int a = vec[0].second +1;
        int b = vec[n-1].second +1;
        int mini = 1e9;
        if(a<=b)
        {
            mini = min(mini,b);
            mini = min(mini,n-a+1);
        }
        if(b<=a)
        {
            mini = min(mini,a);
            mini = min(mini,n-b+1);
        }
        mini = min({mini,b+(n-a+1),a+(n-b+1)});
        return mini;
    }
};