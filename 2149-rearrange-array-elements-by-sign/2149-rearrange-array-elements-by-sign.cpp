class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        vector<int>res;
        for(auto i : nums)
        {
            if(i>0) pos.push_back(i);
            else neg.push_back(i);
        }
        int np=pos.size();
        int nn=neg.size();
        int i=0;
        int j=0;
        while(np>0&&nn>0)
        {
            res.push_back(pos[i]);
            res.push_back(neg[i]);
            i++;
            j++;
            np--;
            nn--;
        }
        return res;
    }
};