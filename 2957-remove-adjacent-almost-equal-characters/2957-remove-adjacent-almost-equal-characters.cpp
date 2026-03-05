class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int cnt =0;
        int n=word.size();
        int i=0;
        while(i<n)
        {
            char next = word[i+1];
            next++;
            char prev = word[i+1];
            prev--;
            bool ok  = false;
            if( (i+1<n && word[i] == next) || (i+1<n && word[i]==word[i+1]) || ( i+1<n && word[i]==prev))
            {
                //cout<< ++word[i+1] << --word[i+1] << word[i];
                cnt++;
                i+=2;
                ok = true;
            }
           if(!ok) i++;
        }
        return cnt;
    }
};