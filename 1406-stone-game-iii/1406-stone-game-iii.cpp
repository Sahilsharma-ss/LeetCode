// stone game 3 

class Solution {
public:
    // int n;
    // vector<int>dp;
    // int cnt =0 ;
    // int solve(int ind,vector<int>&stoneValue)
    // {  
    //     cnt++;
    //     if(ind>=n) return 0;
    //     if(dp[ind] != INT_MIN) return dp[ind];
    //     int take1 =  stoneValue[ind] - solve(ind+1,stoneValue);
    //     int take2 = -1e9;
    //     if(ind+1<n)
    //     {
    //         take2 = stoneValue[ind] + stoneValue[ind+1] - solve(ind+2,stoneValue);
    //     }
    //     int take3 = -1e9;
    //     if(ind+2<n)
    //     {
    //         take3 = stoneValue[ind] + stoneValue[ind+1] + stoneValue[ind+2] - solve(ind+3,stoneValue);
    //     }
    //     return dp[ind] = max({take1,take2,take3});
    // }
    string stoneGameIII(vector<int>& stoneValue) {
        // n = stoneValue.size();
        // dp.assign(n+1,INT_MIN);
        // int ans = solve(0,stoneValue);
        // cout<<cnt<<endl;
        // if(ans==0)
        // {
        //     return "Tie";
        // }else if(ans<0)
        // {
        //     return "Bob";
        // }
        // return "Alice";
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int sum = 0;
            dp[i] = INT_MIN;

            for (int k = 0; k < 3 && i + k < n; k++) {
                sum += stoneValue[i + k];
                dp[i] = max(dp[i], sum - dp[i + k + 1]);
            }
        }

        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};