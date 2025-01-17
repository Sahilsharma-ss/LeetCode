class Solution {
public:
    int maxVowels(string s, int k) {
        int vowel=0;
        for(int i =0;i<k;i++)
        {
            if(isvowel(s[i]))
            {
                vowel++;
            }
        }
        int maxv=vowel;
        int start =0;
        int end=k;
        while(end < s.length())
        {
            if(isvowel(s[start]))
            {
                vowel--;
            }
            start++;
            if(isvowel(s[end]))
            {
                vowel++;
            }
            end++;
            maxv = max(maxv,vowel);
        }
        return maxv;
    }
    bool isvowel(char s)
    {
        if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u')
        {
            return true;
        }
        return false;
    }
};