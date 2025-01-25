class Solution {
public:
    vector<int> minOperations(string boxes) {
        int s=boxes.length();
         vector<int>ans(boxes.length());
        for(int i =0;i<s;i++)
        {
            if(boxes[i]=='1')
            {
            for(int j=0;j<s;j++)
            {
                ans[j]+=abs(j-i);
            }
            }
        }
        return ans;
    }
};