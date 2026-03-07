class Dsu {
public:
    vector<int> parent, rank;
    Dsu(int n) {
        parent.resize(n, 0);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
    int unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb)
            return true;
        if (rank[pa] < rank[pb]) {
            parent[pa] = pb;
        } else if (rank[pb] < rank[pa]) {
            parent[pb] = pa;
        } else {
            parent[pb] = pa;
            rank[pa]++;
        }
        return false;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        Dsu dsu(n);

        unordered_map<string,int> mp;

        //  Union accounts sharing emails
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(mp.find(accounts[i][j])!=mp.end()) 
                {
                    dsu.unite(i, mp[accounts[i][j]]);
                }
                else
                {
                    mp[accounts[i][j]] = i;
                }
            }
        }

        //  Group emails by root account
        unordered_map<int, set<string>> groups;

        for(int i=0;i<n;i++)
        {
            int root = dsu.find(i);
            for(int j=1;j<accounts[i].size();j++)
            {
                groups[root].insert(accounts[i][j]);
            }
        }


        vector<vector<string>> ans;

        for(auto &g : groups)
        {
            vector<string> temp;
            int idx = g.first;

            temp.push_back(accounts[idx][0]); 
            for(auto &email : g.second)
            {
                temp.push_back(email);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};