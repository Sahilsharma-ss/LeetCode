class Solution {
public:
    int cal(int no , int ind,int n)
    {
        while(no>0)
        {
           ind--;
            if(ind<0)
           {
            ind = n-1;
           } 
           no--;
        }
        return ind+1;
    }
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>vec(n);
        for(int i=0;i<n;i++)
        {
            vec[i] = i;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i] >0)
            {
                vec[i] = nums[(i+nums[i])%n];
            }
            else if(nums[i]<0)
            {
                int idx = cal(abs(nums[i]),i,n);
                vec[i]=nums[idx-1] ;
            }
            else
            {
                vec[i] = 0;
            }
        }
        return vec;
    }
};