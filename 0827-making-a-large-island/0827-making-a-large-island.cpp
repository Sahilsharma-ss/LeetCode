class Solution {
public:
    int n;
    inline bool inside(int i, int j){
        return 0<=i && i<n && 0<=j && j<n;
    }
    inline int idx(int i,  int j){
        return i*n+j;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        const int N=n*n;
        const int d[5]={0,1,0,-1,0};
        UnionFind G(N);
        int maxSz=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if (grid[i][j]){
                    int a=idx(i, j), b;
                    int D=(i<n-1)?grid[i+1][j]:0, R=(j<n-1)?grid[i][j+1]:0;
                    if (D>0){// down
                        b=a+n;
                        if (G.Union(a, b))// connect 2 components
                            maxSz=max(maxSz, G.Size[G.Find(a)]);
                    }
                    if (R>0){// right
                        b=a+1;
                        if (G.Union(a, b))// connect 2 components
                            maxSz=max(maxSz, G.Size[G.Find(a)]);
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if (grid[i][j]==0){
                    int component[4]={N, N, N, N};
                    int cz=0;
                    for( int a=0; a<4; a++){
                        const int r=i+d[a], s=j+d[a+1];
                        if (inside(r, s) && grid[r][s]!=0)
                            component[cz++]=G.Find(idx(r, s));
                    }
                    if (cz==0) continue;
                    sort(component, component+cz);
                    int sz=1+G.Size[component[0]];
                    for (int k=1; k<cz; k++)
                        if (component[k]!=component[k-1]) 
                            sz+=G.Size[component[k]];
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