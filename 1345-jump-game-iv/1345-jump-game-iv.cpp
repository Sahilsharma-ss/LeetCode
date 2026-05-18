class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>mp;
        int n = arr.size();
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]].push_back(i);
        }
        queue<pair<pair<int,int>,int>>q; // {{arr[i],ind},steps}
        q.push({{arr[0],0},0});
        vector<int>vis(n,false);
        vis[0] = true;
        while(!q.empty())
        {
            int ele = q.front().first.first;
            int ind = q.front().first.second;
            int st = q.front().second;
            if(ind==n-1)
            {
                return st;
            }
            //if(vis[ind]==true) continue;
            q.pop();
            if(ind+1 <n && !vis[ind+1])
            {
                q.push({{arr[ind+1],ind+1},st+1});
                vis[ind+1] = true;
            }
            if(ind-1 >=0 && !vis[ind-1])
            {
                q.push({{arr[ind-1],ind-1},st+1});
                vis[ind-1] = true;
            }
           // if(mp[ele]==0) continue;

            for(int index : mp[ele])
            {
                if(index!=ind && !vis[index])
                {
                    q.push({{ele,index},st+1});
                    vis[index] = true;
                }
            }
            mp.erase(ele);
        }
        return -1; // dummy
    }
};