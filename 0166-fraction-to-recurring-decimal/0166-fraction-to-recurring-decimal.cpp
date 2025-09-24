class Solution {
public:
    string fractionToDecimal(int n, int d) {
        if (n == 0) return "0";
        string result;
        
        if ((n < 0) ^ (d < 0)) result += "-";
        
        long long numerator = llabs((long long)n);
        long long denominator = llabs((long long)d);
        result += to_string(numerator / denominator);
        long long rem = numerator % denominator;
        if (rem == 0) return result; // no fractional part
        
        result += ".";
        unordered_map<long long, int> seen; // remainder -> index in result
        
        while (rem != 0) {
            if (seen.count(rem)) {
                result.insert(seen[rem], "(");
                result += ")";
                break;
            }
            seen[rem] = result.size();
            rem *= 10;
            result += to_string(rem / denominator);
            rem %= denominator;
        }
        
        return result;
    }
};
