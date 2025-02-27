class Solution {
public:
    int maximumSum(vector<int>& arr) {
        if(arr.size==1&&arr[0]<0) return -1;
        int maxs=arr[0];
        int del=arr[0];
        int no_del=arr[0];
        int n=arr.size();
        for(int i=1;i<n;i++)
        {
            int temp=no_del;
             del=max(temp,del+arr[i]);
             no_del=max(arr[i],no_del+arr[i]);
             maxs=max(maxs,max(del,no_del));
        }
        return (maxs<0)?-1:maxs;
    }
    
};