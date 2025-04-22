class Solution {
public:
    int climbStairs(int n) {
        if(n==0||n==1||n==2) return n;
        vector<int>vec(n+1);
        vec[0]=0;//way to climb 0 stair
        vec[1]=1;//way to climb 1 stair
        vec[2]=2;
        for(int i=3;i<=n;i++)
        {
            vec[i]=vec[i-2]+vec[i-1];
        }
        return vec[n];
    }
};