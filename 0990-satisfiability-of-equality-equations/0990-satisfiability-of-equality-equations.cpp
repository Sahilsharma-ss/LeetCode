class Solution {
public:

    vector<int>parent;
    vector<int>rank;
    
    int find(int x)
    {
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y)
    {
        int x_p=find(x);
        int y_p=find(y);
        if(x_p==y_p) return;
        if(x_p>y_p)
        {
            parent[y_p]=x_p;
        }
        else if(x_p<y_p)
        {
            parent[x_p]=y_p;
        }
        else
        {
            parent[x_p]=y_p;
            rank[y_p]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
        }
        int flag=0;
        for(string &s : equations)
        {
            if(s[1]=='=')
            {
                Union(s[0]-'a',s[3]-'a');
            }
        }
        for(string &s : equations)
        {
            if(s[1]=='!')
            {
                int x=find(s[0]-'a');
                int y=find(s[3]-'a');
                if(x==y)
                {
                    return false;
                }
            }
        }
        return true;
    }
};