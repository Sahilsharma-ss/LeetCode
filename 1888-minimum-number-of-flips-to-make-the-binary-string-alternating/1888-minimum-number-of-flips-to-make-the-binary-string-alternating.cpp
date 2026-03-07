class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string t = s + s;

        string str0="", str1="";
        for(int i=0;i<2*n;i++){
            str0 += (i%2==0 ? '0':'1'); // 0101...
            str1 += (i%2==0 ? '1':'0'); // 1010...
        }

        int cnt1=0, cnt2=0;
        int ans = INT_MAX;

        for(int i=0;i<2*n;i++){
            if(t[i]!=str0[i]) cnt1++;
            if(t[i]!=str1[i]) cnt2++;
            if(i>=n){
                if(t[i-n]!=str0[i-n]) cnt1--;
                if(t[i-n]!=str1[i-n]) cnt2--;
            }
            if(i>=n-1){
                ans = min({ans,cnt1,cnt2});
            }
        }
        return ans;
    }
};