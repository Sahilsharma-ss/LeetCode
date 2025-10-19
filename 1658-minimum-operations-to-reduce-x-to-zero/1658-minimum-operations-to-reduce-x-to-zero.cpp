class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(x>sum) return -1;
        int n=nums.size();
        vector<int>pref(n),suff(n);
        unordered_map<int,int>mp1,mp2;
        pref[0]=nums[0];
        mp1[nums[0]] = 0;
        for(int i =1;i<n;i++)
        {
            pref[i]=pref[i-1]+nums[i];
            mp1[pref[i]] = i;
        }
        suff[n-1] = nums[n-1];
        mp2[nums[n-1]] = 0;
        int ind=1;
        for(int i=n-2;i>=0;i--)
        {
            suff[i] = suff[i+1] + nums[i];
            mp2[suff[i]] = ind++;
        }
         sort(suff.begin(),suff.end());
         int mini1=1e9;
        for(auto i : pref)
        {
            int target  = x-i;
            if(target<0) continue;
            cout<<target<<endl;
            if(binary_search(suff.begin(),suff.end(),target))
            {
                cout<<"hello";
               mini1 = min(mini1, (mp2[target]+1) + (mp1[i]+1));
            }
        }
        int a=1e9,b=1e9;
        if(mp1.find(x)!=mp1.end()) a= mp1[x]+1;
        if(mp2.find(x)!=mp2.end()) b= mp2[x]+1;
        // if(a!=-1 && b!=-1)
        // {
        //     return min(a,b);
        // }
        // else if(a=-1)
        // {
        //     return b;
        // }
        // else if(b=-1)
        // {
        //     return a;
        // }
        // sort(suff.begin(),suff.end());
        // for(auto i : pref)
        // {
        //     int target  = x-i;
        //     if(target<0) continue;
        //     cout<<target<<endl;
        //     if(binary_search(suff.begin(),suff.end(),target))
        //     {
        //         cout<<"hello";
        //         return (mp2[target]+1) + (mp1[i]+1);
        //     }
        // }
       int  ans= min({mini1,a,b});
        return ans==1e9?-1:ans;
    }
};