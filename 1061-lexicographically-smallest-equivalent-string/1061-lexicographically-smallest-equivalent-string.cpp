class Solution {
public:
    vector<int>parent;
    int find(int x)
    {
        if(parent[x]==x) return x;
        return find(parent[x]);
    }
    void unite(int a, int b) {
        int p_a = find(a);
        int p_b = find(b);
        if (p_a == p_b) return;
        if (p_a < p_b)
        parent[p_b] = p_a;
        else
        parent[p_a] = p_b;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<s1.size();i++)
        {
            unite(s1[i]-'a',s2[i]-'a');
        }
        string res="";
        for(char c : baseStr)
        {
            res+=find(c-'a')+'a';
        }
        return res;
    }
};