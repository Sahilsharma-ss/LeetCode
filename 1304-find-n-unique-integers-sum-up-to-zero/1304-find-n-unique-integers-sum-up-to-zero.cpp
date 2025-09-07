class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>res;
        int i=1;
        int no=n/2;
        if(n==1) return {0};
        if(n%2==0)
        {
            while(no--)
            {
                res.push_back(i);
                res.push_back(-i);
                i++;
            }
        }
        else
        {
            int j=0;
            while(j<=n/2)
            {
                res.push_back(i);
                if(((n/2)-j)<=1)
                {
                    res.push_back(i+1);
                    res.push_back(-(i+(i+1)));
                    break;
                }
                else
                {
                    res.push_back(-i);
                }
                i++;
                j++;
            }
        }
        return res;
    }
};