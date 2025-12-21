class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt = 0;
        int n  = strs.size();
        vector<string>vec(n);
        for(int i=0;i<strs[0].size();i++)
        {
            bool isok  = true;
            for(int j=0;j<strs.size()-1;j++)
            {
               if(vec[j]+strs[j][i] > vec[j+1]+strs[j+1][i])
               {
                    cnt++;
                    isok = false;
                    break;
               }
            }
            if(isok)
            {
                for(int j = 0 ;j<strs.size();j++)
                {
                    vec[j] +=strs[j][i];
                }
            }
        }
        return cnt;
    }
};