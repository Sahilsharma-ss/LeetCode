class Solution {
public:

    long long solve(string &str,string& inputs,int limit)
    {
        if(str.length()<inputs.length())
        {
            return 0;
        }
        long long cnt=0;
        string trial=str.substr(str.length()-inputs.length());
        int remainl=str.length()-inputs.length();

        for(int i=0;i<remainl;i++)
        {
            int digit=str[i]-'0';
            if(digit<=limit)
            {
                cnt +=digit*pow(limit+1,remainl-i-1);
            }
            else
            {
                cnt +=pow(limit+1,remainl-i);
                return cnt;
            }
        }
        if(trial >=inputs) 
        {
            cnt +=1;
        }
        return cnt;

    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string startstr=to_string(start-1);
        string finishstr=to_string(finish);
        return solve(finishstr,s,limit)-solve(startstr,s,limit);
    }
};