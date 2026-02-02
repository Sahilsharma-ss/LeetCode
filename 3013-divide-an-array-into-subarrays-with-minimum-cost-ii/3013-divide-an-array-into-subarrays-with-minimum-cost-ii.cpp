//brute
// typedef pair<int, int> p;
// class Solution {
// public:
//     long long minimumCost(vector<int>& nums, int k, int dist) {
//         priority_queue<p, vector<p>, greater<p>> pq;
//         int n = nums.size();
//         long long res = 1e18;
//         for (int j = 1; j < n; j++) {
//             int need = k;
//             long long ans = nums[0];
//             for (int i = j + 1; i <n; i++) {
//                 pq.push({nums[i], i});
//             }
//             int second_ind = j;
//             ans += nums[j];
//            need = need-2; // two index element are already added
//            // cout<< pq.top().first<<ans;
//            int cnt =0;
//             while (!pq.empty() && need > 0) {
//                 if ((pq.top().second - second_ind) <= dist) {
//                     ans += pq.top().first;
//                     need--;
//                 }
//                 pq.pop();
//             }
//            if(need==0) res = min(res, ans);
//             while(!pq.empty())
//             {
//                 pq.pop();
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll> P;

    ll minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();

        set<P> kMinimum; //stores (k-1) minimum elements
        set<P> remaining;

        ll sum = 0; //stores sum of (k-1) min elements

        int i = 1;
        while(i - dist < 1) {
            kMinimum.insert({nums[i], i});
            sum += nums[i];
            if(kMinimum.size() > k-1) {
                P temp = *kMinimum.rbegin();
                sum -= temp.first;
                remaining.insert(temp);
                kMinimum.erase(temp);
            }
            i++;
        }

        ll result = LONG_MAX; //stores min sum of (k-1) elements
        //0, 1, ...... i
        while(i < n) {
            kMinimum.insert({nums[i], i});
            sum += nums[i];

            if(kMinimum.size() > k-1) {
                P temp = *kMinimum.rbegin();
                sum -= temp.first;
                remaining.insert(temp);
                kMinimum.erase(temp);
            }

            result = min(result, sum);

            //shift window
            //i-dist wala element will be removed
            P remove = {nums[i-dist], i-dist};
            if(kMinimum.count(remove)) {
                kMinimum.erase(remove);
                sum -= remove.first;

                if(!remaining.empty()) {
                    P temp = *remaining.begin();
                    kMinimum.insert(temp);
                    sum += temp.first;
                    remaining.erase(temp);
                }
            } else {
                remaining.erase(remove);
            }

            i++;
        }

        return nums[0] + result;
    }
};