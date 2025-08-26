class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        vector<pair<double,int>>vec;
        for(auto i : dimensions)
        {
            int l =i[0];
            int w=i[1];
            vec.push_back({sqrt((l*l)+(w*w)),(l*w)});
        }
        sort(vec.begin(),vec.end(),[&](auto i ,auto j){
            return i.first>j.first;
        });
        if(vec.size()>1&&vec[0].first!=vec[1].first)
        {
            return vec[0].second;
        }   
        int maxi =vec[0].second;
        int i=1;
            while(i<vec.size()&&vec[i-1].first==vec[i].first)
            {
                maxi=max(maxi,vec[i].second);
                i++;
            }
            return maxi;
    }
};