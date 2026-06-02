class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        vector<vector<int>>lr,wr;
        int n = landStartTime.size();
        for(int i = 0 ; i<n;i++)
        {
            lr.push_back({landStartTime[i],landDuration[i]});
        }
        int m= waterStartTime.size();
        for(int i = 0 ; i<m;i++)
        {
            wr.push_back({waterStartTime[i],waterDuration[i]});
        }
        int mini = 1e9;
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                int lrtot = lr[i][1]+lr[i][0];
                if(wr[j][0] >= lrtot)
                {
                    mini = min(mini,wr[j][0]-lrtot + wr[j][1] + lrtot);
                }
                else if(wr[j][0] < lrtot)
                {
                    mini = min(mini,wr[j][1] + lrtot);
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                int lrtot = wr[i][1]+wr[i][0];
                if(lr[j][0] >= lrtot)
                {
                    mini = min(mini,lr[j][0]-lrtot + lr[j][1] + lrtot);
                }
                 else if(lr[j][0] < lrtot)
                {
                    mini = min(mini,lr[j][1] + lrtot);
                }
            }
        }
        return mini;
    }
};