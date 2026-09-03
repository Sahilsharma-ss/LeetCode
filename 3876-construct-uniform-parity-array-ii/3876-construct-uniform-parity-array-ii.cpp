class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        //  int minodd = 1e9;
        // int mineven  =1e9;
        // bool isodd = false;
        // bool isven = false;
        // int n = nums1.size();
        // for(int i=0;i<n;i++)
        //     {
        //         if(nums1[i]%2==1)
        //         {
        //             iseven = true;
        //             minodd = min(minodd,nums1[i]);
        //         }
        //         else
        //         {
        //             isodd = true;
        //             mineven = min(minevem,nums1[i]);
        //         }
        //     }
        //    if(!isodd ||  !iseven) return true;
        int minodd = 1e9;
        int mineven  =1e9;
        bool isodd = false;
        bool iseven = false;
        int n = nums1.size();
        for(int i=0;i<n;i++)
            {
                if(nums1[i]%2==1)
                {
                    iseven = true;
                    minodd = min(minodd,nums1[i]);
                }
                else
                {
                    isodd = true;
                    mineven = min(mineven,nums1[i]);
                }
            }
           if(!isodd ||  !iseven) return true;
            if(minodd < mineven) return true;
        return false;;
    }
};