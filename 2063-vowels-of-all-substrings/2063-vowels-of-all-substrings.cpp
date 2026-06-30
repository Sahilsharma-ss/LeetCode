class Solution {
public:
    long long countVowels(string word) {
        long long  ans =0;
        int n = word.size();
        long long inc =1;
        for(int i =0;i<word.size();i++)
        {
            if(word[i]=='a' ||word[i]=='e' ||word[i]=='o' ||word[i]=='i' ||word[i]=='u')
            {
                 ans += 1LL*(i+1)*(n-i);
            }
        }
        return ans;
    }
};