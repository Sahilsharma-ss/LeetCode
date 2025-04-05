class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto &i : image)
        {
            reverse(i.begin(),i.end());
        }
        for(auto &i : image)
        {
            for(int j=0;j<i.size();j++)
            {
                i[j]=i[j]^1;
            }
        }
        return image;
    }
};