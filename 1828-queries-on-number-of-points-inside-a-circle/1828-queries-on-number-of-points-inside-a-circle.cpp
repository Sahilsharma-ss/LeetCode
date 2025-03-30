class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int>res;
        for(auto i : queries)
        {
            int h=i[0];
            int k=i[1];
            int r=i[2];
            int c=0;
            for(auto i : points)
            {
                int x=i[0];
                int y=i[1];
                if(((x-h)*(x-h))+((y-k)*(y-k))<=(r*r))
                {
                    c++;
                }
            }
            res.push_back(c);
        }
        return res;
    }
};