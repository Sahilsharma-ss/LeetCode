class Solution {
public:
    int numberOfSpecialChars(string word) {
         vector<int>a(26,0),A(26,0);
         int cnt = 0;
        for(int i=0;i<word.size();i++)
        {
            char ch = word[i];
            // if(ch=='C') break;
            if(ch>='a' && ch<='z')
            {
                a[ch-'a'] = i+1;
            }
            if(ch>='A' && ch<='Z')
            {
               if(A[ch-'A'] == 0) A[ch-'A']  = i+1;
            }
        }
        for(auto i=0;i<26;i++)
        {
            if(a[i] && A[i] && a[i] < A[i])
            {
                cnt++;
            }
        }
        return cnt;
    }
};