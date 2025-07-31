class Solution {
public:
    int n, N;
    inline bool inside(int i, int j){
        return 0<=i && i<n && 0<=j && j<n;
    }
    inline int idx(int i,  int j){
        return i*n+j;
    }
    const int d[5]={0, 1, 0, -1, 0};
    vector<int> viz;// -1 for unvisited, other for component number

    int dfs(int i, int j, int comp, vector<vector<int>>& grid) {
        viz[idx(i, j)] = comp;
        int cnt = 1;
        for (int a=0; a < 4; a++) {
            int r=i+d[a], s=j+d[a+1];
            if (inside(r, s) && grid[r][s]==1 && viz[idx(r, s)]==-1)
                cnt+= dfs(r, s, comp, grid);
        }
        return cnt;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        N = n*n;
        viz.assign(N, -1);
        
        int maxSz=1, comp=0;
        vector<int> Size; // size for component[comp]  

        // Find components
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]==1 && viz[idx(i, j)]==-1) {
                    int cnt=dfs(i, j, comp++, grid);
                    Size.push_back(cnt);
                    maxSz=max(maxSz, cnt);
                }
            }
        }

        // 2nd loop
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if (grid[i][j]==0){
                    int component[4]={N, N, N, N};
                    int cz=0;
                    for( int a=0; a<4; a++){
                        const int r=i+d[a], s=j+d[a+1];
                        if (inside(r, s) && grid[r][s]!=0)
                            component[cz++]=viz[idx(r, s)];
                    }
                    if (cz==0) continue;
                    sort(component, component+cz);
                    int sz=1+Size[component[0]];
                    for (int k=1; k<cz; k++)
                        if (component[k]!=component[k-1]) 
                            sz+=Size[component[k]];
                    maxSz=max(maxSz, sz);
                }
            }
        }
        return maxSz;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();