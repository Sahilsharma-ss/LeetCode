class Solution {
public:
    bool canChange(string start, string target) {
        // Step 1: Remove underscores and compare order
        string s1, s2;
        for (char c : start) if (c != '_') s1 += c;
        for (char c : target) if (c != '_') s2 += c;
        if (s1 != s2) return false;

        // Step 2: Two pointers
        int n = start.size();
        int i = 0, j = 0;

        while (i < n && j < n) {
            while (i < n && start[i] == '_') i++;
            while (j < n && target[j] == '_') j++;
            if (i == n || j == n) break;

            // If the pieces differ, impossible
            if (start[i] != target[j]) return false;

            // Check movement rules
            if (start[i] == 'L' && i < j) return false; // L can’t move right
            if (start[i] == 'R' && i > j) return false; // R can’t move left

            i++; j++;
        }

        return true;
    }
};
