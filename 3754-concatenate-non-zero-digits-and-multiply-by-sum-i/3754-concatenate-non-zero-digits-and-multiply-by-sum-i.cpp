class Solution {
public:
    long long sumAndMultiply(int n) {
        string str="";
        int temp =n;
        int sum = 0;
        int cnt =0;
        while(temp>0)
        {
            int no = temp%10;
            sum +=no;
            if(no!=0)
            {
                str+=no+'0';
                cnt++;
            }
               temp/=10;
        }
        if(cnt==0) return 0;
        reverse(str.begin(),str.end());
        long long ans = std :: stoi(str);
         ans *=sum;
         return ans;
    }
};