class Solution {
public:
    vector<pair<int,int>>dir{{1,0},{-1,0},{0,1},{0,-1}};
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(auto i : walls)
        {
            visited[i[0]][i[1]] = 2;
        }
        for(auto i : guards)
        {
            visited[i[0]][i[1]] = 3;
        }
        for(auto &g : guards)
        {
            int i = g[0];
            int j = g[1];
            for(auto &d : dir)
            {
                int a = d.first;
                int b = d.second;
                int i_ = i + a;
                int j_ = j + b;
                while(i_ < m && j_ < n && i_ >= 0 && j_ >= 0)
                {
                    if(visited[i_][j_] == 2 || visited[i_][j_] == 3) break;
                    if(visited[i_][j_] == 0) visited[i_][j_] = 1;
                    i_ += a;
                    j_ += b;
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(visited[i][j] == 0)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
