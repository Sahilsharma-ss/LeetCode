class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      int n=numRows;
      if(n==1) return  {{1}};
      if(n==2) return {{1},{1,1}};
      vector<vector<int>>vec;
      vec.push_back({1});
      vec.push_back({1,1});
      vector<int>prev{1,1};
      for(int i=2;i<n;i++)
      {
            vector<int>curr;
            curr.push_back(1);
            for(int j=1;j<prev.size();j++)
            {
                int val=prev[j-1]+prev[j];
                curr.push_back(val);
            }
            curr.push_back(1);
            vec.push_back(curr);
            prev=curr;
      }
      return vec;

    }
};