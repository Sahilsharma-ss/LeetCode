class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        if(m < 3 || n < 3) return 0; // all boundries

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || i == m-1 || j == 0 || j == n-1){
                    pq.push({heightMap[i][j],{i,j}}); // all boundries
                    visited[i][j] = true;
                }
            }
        }
        vector<pair<int,int>> direction = {{0,-1}, {0,1}, {-1,0}, {1,0}};

        int result = 0;

        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            int height = curr.first;
            int cx = curr.second.first;
            int cy = curr.second.second;

            for(auto dir : direction){
                int nx = cx + dir.first;
                int ny = cy + dir.second;

                if(nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    result = result + max(height - heightMap[nx][ny], 0); // taking zero in sum if negative
                    pq.push({max(heightMap[nx][ny], height), {nx,ny}}); // pass height of maximum
                }
            }
        }
        return result;
    }
};