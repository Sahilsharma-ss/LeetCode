class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        vector<int> eleven = {11,111,1111,11111,111111,1111111,11111111,111111111};

        for (int ind = 0; ind < 8; ind++) {
            int no = 0;
            for (int d = 1; d <= ind + 1; d++)
                no = no * 10 + d;

            while (true) {
                int curr = no + eleven[ind];

                if (curr >= low && curr <= high)
                    res.push_back(curr);

                if (curr % 10 == 9)
                    break;

                no += eleven[ind];
            }
        }

        return res;
    }
};