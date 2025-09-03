
class Solution {
public:
    bool nopoint(int a ,int b,int c,int d,vector<vector<int>>& points)
    {
        for(auto i : points)
        {
            int x=i[0];
            int y=i[1];
            if(x==a&&y==b || x==c&&y==d) continue;
            if(x>=a&&x<=c && y<=b&&y>=d)
            {
                return false;
            }
        }
        return true;
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int a=points[i][0];
                int b=points[i][1];
                int c=points[j][0];
                int d=points[j][1];
                if (i == j) continue;
                if (i == j) continue;
                if (((a < c && b >= d) || (a == c && b > d)) && nopoint(min(a,c), max(b,d), max(a,c), min(b,d), points)) {
                    cnt++;
                }


            }
        }
        return cnt;
    }
};