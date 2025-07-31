class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>prev,curr,res;
        for(int i=0;i<arr.size();i++)//O(n)
        {
            for(int x : prev) //O(1)   can have max 32 values 
            {
                curr.insert(x|arr[i]);
                res.insert(x|arr[i]);
            }
            curr.insert(arr[i]);
            res.insert(arr[i]);
            prev=curr;
            curr.clear();
        }
        return res.size();
    }
};