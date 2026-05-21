class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int>mp,mp1;
        for(int i=0;i<arr2.size();i++)
        {
            string tmp = to_string(arr2[i]);
            string num = "";
            for(int j=0;j<tmp.size();j++)
            {
                num +=tmp[j];
               mp[num]++;
            }
        }
         for(int i=0;i<arr1.size();i++)
        {
            string tmp = to_string(arr1[i]);
            string num = "";
            for(int j=0;j<tmp.size();j++)
            {
                num +=tmp[j];
               mp1[num]++;
            }
        }
        int maxi = 0;
        for(auto i : mp)
        {
           // cout<<i.first<<": "<<i.second<<endl;
            if(mp1[i.first]!=0)
            {
                int sz = i.first.size();
                maxi = max(maxi,sz);
            }
        }
        return maxi;
    }
};