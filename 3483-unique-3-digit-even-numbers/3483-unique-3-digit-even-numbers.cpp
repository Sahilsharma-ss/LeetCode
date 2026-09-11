class Solution {
public:
    bool check1(vector<int>&a,vector<int>&b)
    {
        for(int i =0;i<a.size();i++)
        {
            if(a[i]>b[i])
            {
                return false;
            }
        }
        return true;
    }
    int totalNumbers(vector<int>& digits) {
        
        int n = digits.size();
        vector<int>digit(11);
        for(int i = 0;i<n;i++)
        {
            digit[digits[i]]++;
        }
        int ans = 0;
        for(int i =100 ;i<=999;i++)
        {
            vector<int>check(11);
            int temp = i;
            while(temp>0)
            {
                check[temp%10]++;
                temp/=10;
            }
            if(check1(check,digit) && i%2==0)
            {
                ans++;
            }
        }
        return ans;
    }
};