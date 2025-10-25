class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9*num) return "";
        string ans = "";
        for(int i = 0; i < num; i++){
            int d = 0;
            if(sum < 9){
                d = sum;    
            }else{
                d = 9;
            }
            ans += (d+'0');
            sum -= d;
        }
        return ans;
    }
};