#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    long long minOperations(vector<int>& nums) {
        vector<ll> even, odd;

        for(int len = 1; len <= 9; len++) {
            int half = (len + 1) / 2;

            ll st = pow(10, half - 1);
            ll en = pow(10, half);

            for(ll i = st; i < en; i++) {
                ll left = i;
                ll right = 0;

                ll temp = (len % 2 == 0) ? i : i / 10;

                while(temp > 0) {
                    right = right * 10 + temp % 10;
                    temp /= 10;
                    left *= 10;  //  shift left to right so that we can add right in end
                }

                ll p = left + right;

                if(p > 2000000002LL) continue;

                if(p % 2 == 0)
                    even.push_back(p);
                else
                    odd.push_back(p);
            }
        }

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());

        ll ans = 0;

        for(int x : nums) {
            vector<ll>& v = (x % 2 == 0) ? even : odd;

            auto it = lower_bound(v.begin(), v.end(), x);

            ll cost = LLONG_MAX;

            if(it != v.end()) {
                cost = min(cost, (*it - x) / 2);
            }

            if(it != v.begin()) {
                it--;
                cost = min(cost, (x - *it) / 2);
            }

            ans += cost;
        }

        return ans;
    }
};