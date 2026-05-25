class Solution {
public:

    bool canReach(string s, int minJump, int maxJump) {

        int n = s.size();

        vector<bool> vis(n,false);

        queue<int> q;

        q.push(0);

        vis[0] = true;

        int farthest = 0;

        while(!q.empty())
        {
            int i = q.front();
            q.pop();

            int start = max(i + minJump, farthest + 1);
            int end = min(i + maxJump, n - 1);

            for(int j = start; j <= end; j++)
            {
                if(s[j] == '0' && !vis[j])
                {
                    if(j == n-1)
                        return true;

                    vis[j] = true;

                    q.push(j);
                }
            }

            farthest = max(farthest, end);
        }

        return vis[n-1];
    }
};