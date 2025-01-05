class Solution {
public:
    string addBinary(string a, string b) {
        string result = ""; 
        int carry = 0;    
        int i = a.size() - 1; 
        int j = b.size() - 1; 

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry; // Start with the carry
            
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0'; 
            
            carry = sum / 2; // Update carry (sum divided by 2)
            result += (sum % 2) + '0'; 
        }

        reverse(result.begin(), result.end()); // Reverse the result string
        return result;
    }
};
