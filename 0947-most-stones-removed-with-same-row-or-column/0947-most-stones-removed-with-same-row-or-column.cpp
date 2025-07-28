class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int a) {
        if (parent[a] != a)
            parent[a] = find(parent[a]);
        return parent[a];
    }

    void Union(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) return;
        if (rank[pa] < rank[pb]) {
            parent[pa] = pb;
        } else if (rank[pa] > rank[pb]) {
            parent[pb] = pa;
        } else {
            parent[pa] = pb;
            rank[pb]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        for (auto& stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        int size = maxRow + maxCol + 2;
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) parent[i] = i;

        for (auto& stone : stones) {
            int r = stone[0];
            int c = stone[1] + maxRow + 1;
            Union(r, c);
        }

        set<int> roots;
        for (auto& stone : stones) {
            int r = stone[0];
            int c = stone[1] + maxRow + 1;
            roots.insert(find(r));
            roots.insert(find(c));
        }

        return stones.size() - roots.size();
    }
};
