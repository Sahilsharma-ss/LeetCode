class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& nums) {
        vector<int> freq(10, 0);
        for (int num : nums)
            freq[num]++;

        set<int> s;

        for (int num = 100; num <= 999; num += 2) {  // Only even 3-digit numbers
            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            vector<int> tempFreq = freq;
            if (tempFreq[a] > 0) tempFreq[a]--;
            else continue;

            if (tempFreq[b] > 0) tempFreq[b]--;
            else continue;

            if (tempFreq[c] > 0)
                s.insert(num);
        }

        return vector<int>(s.begin(), s.end());
    }
};
