class Solution {
public:
    vector<bool> sieve(int n) {
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
        return prime;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime = sieve(right); 
        vector<int> vec;

        for (int i = left; i <= right; i++) {
            if (prime[i]) {
                vec.push_back(i);
            }
        }

        if (vec.size() < 2)
            return {-1, -1};

        int minDiff = INT_MAX;
        vector<int> result(2, -1);

        for (int i = 1; i < vec.size(); i++) {
            if (vec[i] - vec[i - 1] < minDiff) {
                minDiff = vec[i] - vec[i - 1];
                result[0] = vec[i - 1];
                result[1] = vec[i];
            }
        }

        return result;
    }
};