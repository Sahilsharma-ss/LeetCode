class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& a) {

        sort(a.begin(), a.end(), [&](auto &x, auto &y){
            if (x[1] != y[1]) return x[1] < y[1];
            return x[0] > y[0];
        });

        unordered_set<int> st;

        int l = a[0][0], r = a[0][1];
        st.insert(r - 1);
        st.insert(r);

        for (int i = 1; i < a.size(); i++) {
            int L = a[i][0], R = a[i][1];

            int c = 0;
            for (int x : st) {
                if (x >= L && x <= R) c++;
                if (c >= 2) break;
            }

            if (c >= 2) continue;

            if (c == 1) {
                for (int x = R; x >= L; x--) {
                    if (!st.count(x)) {
                        st.insert(x);
                        break;
                    }
                }
            } else {
                st.insert(R - 1);
                st.insert(R);
            }
        }

        return st.size();
    }
};
