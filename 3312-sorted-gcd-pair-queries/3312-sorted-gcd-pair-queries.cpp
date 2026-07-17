class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        vector<long long>freq(maxi+1,0);
        for(auto i : nums) //n*sqrt(n)
        {
            int no = i;
            for(int j=1;j*j<=no;j++)
            {
                if(no%j==0)
                {
                    freq[j]++;
                    if(j != (no/j))
                    {
                        freq[(no/j)]++;
                    }
                }
            }
        }

        for(int i =0;i<=maxi;i++)
        {
            int a = freq[i];
            freq[i] = (1ll*a*(a-1))/2;
        }

        for(int i=maxi;i>=1;i--)
        {
            for(int j=2*i;j<=maxi;j+=i)
            {
                freq[i]-=freq[j];
            }
        }
        for(int i =1 ;i<=maxi;i++)
        {
            freq[i] = freq[i-1]+freq[i];
        }

        vector<int>res;
        for(auto i : queries)
        {
            long long val = i+1;
            int l = 0;
            int r = maxi;
            int ans = 0;
            while(l<=r)
            {
                int mid = l+(r-l)/2;
                if(freq[mid]>=val)
                {
                    ans = mid;
                    r = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};