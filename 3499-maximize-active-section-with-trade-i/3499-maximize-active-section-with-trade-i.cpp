class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string str = "1";
        str+=s;
        str+="1";
        s = str;
        int n = s.size();
        vector<int>inc1(n),inc0(n),dec1(n),dec0(n);
        s[0]=='0'?inc0[0] = 1 : inc1[0] = 1;
        for(int i=1;i<n;i++)
        {
            if(s[i]=='0')
            {
                inc0[i] = inc0[i-1] +1;
            }
            else
            {
                inc0[i] = 0; 
            }
            inc1[i] = inc1[i-1];
            if(s[i]=='1')
            {
                inc1[i] = inc1[i-1] +1;
            }
        }
        s[n-1]=='0'?dec0[n-1] = 1 : dec1[n-1] = 1;
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]=='0')
            {
                dec0[i] = dec0[i+1] +1;
            }
            else
            {
                dec0[i] = 0; 
            }
            dec1[i] = dec1[i+1];
            if(s[i]=='1')
            {
                dec1[i] = dec1[i+1]+1;
            }
            
        }
            int i =0;
            int ans = inc1[n-1] - 2; 
            while(i<n)
            {
                if(s[i]=='1')
                {
                    int zinc  =  0;
                    if(i-1>=0)
                    {
                        if(inc0[i-1]==0)
                        {
                            zinc = -1e9;
                        }
                        else
                        {
                            zinc = inc0[i-1];
                        }
                    }
                    else
                    {
                        zinc = -1e9;         
                    }
                    int lc  = (i-1>=0?inc1[i-1]:0) + zinc;
                    int cnt = 0;
                    while(i<n && s[i]=='1')
                    {
                        cnt++;
                        i++;
                    }
                    int zdec  =  0;
                    if(i<n)                               
                    {
                        if(dec0[i]==0)                
                        {
                            zdec = -1e9;
                        }
                        else
                        {
                            zdec = dec0[i];               
                        }
                    }
                    else
                    {
                        zdec = -1e9;        
                    }
                    int rc = (i<n?dec1[i]:0) + zdec;          
                    ans  = max(ans,lc+rc+cnt-2);
                    i--;
                }
                i++;
            }
        return ans;
    }
};