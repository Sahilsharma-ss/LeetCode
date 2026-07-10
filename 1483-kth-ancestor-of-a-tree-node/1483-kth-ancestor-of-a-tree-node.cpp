class TreeAncestor {
public:
    vector<vector<int>>up;
    int sz;
    TreeAncestor(int n, vector<int>& parent) {
        // given parent array denotes immediate parent for current node
        sz = log2(n)+1;
        up.resize(n,vector<int>(sz,-1));
        for(int i=0;i<n;i++)
        {
            up[i][0] = parent[i];
        }
        for(int j=1;j<sz;j++)
        {
            for(int node=0;node<n;node++)
            {
                if(up[node][j-1]!=-1) up[node][j] = up[up[node][j-1]][j-1];
            }
        }
        // for(auto i : up)
        // {
        //     for(auto j : i)
        //     {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    
    int getKthAncestor(int node, int k) {
       string str =  bitset<32>(k).to_string();
        str = str.substr(str.find('1'));
       // if(k>sz) return -1;
        //cout<<str<<" ";
        int n = str.size()-1;
        for(auto i : str)
        {
            if(i=='1')
            {
                node = up[node][n];
                if (node == -1) return -1;
                n--;
            }
            else
            {
                n--;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */