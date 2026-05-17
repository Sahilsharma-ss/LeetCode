class Solution {
public:
    // int n;
    // vector<int>dp;
    // bool solve(int ind ,vector<int>&arr)
    // {
    //     if(ind >=n || ind<0) return false;
    //     if(arr[ind]==0) return true;
    //     if(dp[ind]!=-1) return dp[ind];
    //     return dp[ind] = solve(ind+arr[ind],arr) || solve(ind-arr[ind],arr);
    // }
    bool canReach(vector<int>& arr, int start) {
        queue<int>q;
        int n = arr.size();
        q.push(start);
        vector<int>vis(n,false);
        vis[start] = true;
        while(!q.empty())
        {
            int ind = q.front();
            if(arr[ind]==0) return true;
            q.pop();
            int indl = ind+arr[ind];
            if(indl<n && indl>=0 && !vis[indl])
            {
                q.push(indl);
                vis[indl] = true;
            }
            int indr = ind-arr[ind];
            if(indr<n && indr>=0 && !vis[indr])
            {
                q.push(indr);
                vis[indr] = true;
            }
        }
        return false;
    }
};