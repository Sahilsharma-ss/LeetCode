typedef pair<long long,pair<int,int>> p;
class Segtree{
    vector<int>segtree,segtree2;
    public : 
    Segtree(vector<int>&arr)
    {
        segtree.resize(4*arr.size());
        segtree2.resize(4*arr.size());
        build(0,0,arr.size()-1,arr);
        build1(0,0,arr.size()-1,arr);
    }
    void build(int i,int l,int r,vector<int>&arr)
    {
        if(l==r)
        {
            segtree[i] = arr[l];
            return;
        }
        int mid = l+(r-l)/2;
        build(2*i+1,l,mid,arr);
        build(2*i+2,mid+1,r,arr);
        segtree[i] = max(segtree[2*i+1],segtree[2*i+2]);
    }
    void build1(int i,int l,int r,vector<int>&arr)
    {
        if(l==r)
        {
            segtree2[i] = arr[l];
            return;
        }
        int mid = l+(r-l)/2;
        build1(2*i+1,l,mid,arr);
        build1(2*i+2,mid+1,r,arr);
        segtree2[i] = min(segtree2[2*i+1],segtree2[2*i+2]);
    }
    int rmq(int i ,int l,int r,int st,int end)
    {
        if(l>end || r<st)
        {
            return -1e9;
        }
        else if(l>=st && r<=end)
        {
            return segtree[i];
        }
            int mid = l+(r-l)/2;
            return max(
                rmq(2*i+1,l,mid,st,end),
                rmq(2*i+2,mid+1,r,st,end)
            );
    }
    int rminq(int i ,int l,int r,int st,int end)
    {
        if(l>end || r<st)
        {
            return 1e9;
        }
        else if(l>=st && r<=end)
        {
            return segtree2[i];
        }
            int mid = l+(r-l)/2;
            return min(
                rminq(2*i+1,l,mid,st,end),
                rminq(2*i+2,mid+1,r,st,end)
            );
    }
};
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        Segtree s(nums);
        priority_queue<p>pq;
        int n = nums.size();
        for(int i =0;i<n;i++)
        {
            pq.push({(s.rmq(0,0,n-1,i,n-1)-s.rminq(0,0,n-1,i,n-1)),{i,n-1}});
        }
        long long sum = 0;
        while(k>0)
        {
            long long val = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            pq.push({s.rmq(0,0,n-1,i,j-1)-s.rminq(0,0,n-1,i,j-1),{i,j-1}});
            sum+=val;
            k--;
        }
        return sum;
    }
};