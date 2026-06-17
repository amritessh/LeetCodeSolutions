class Solution {
public:
    char processStr(string s, long long k) {
        vector<long long> lens;
        long long len = 0;
        
        // First pass: calculate lengths after each operation
        for (char c : s) {
            if (islower(c)) {
                len++;
            } else if (c == '*') {
                if (len > 0) len--;
            } else if (c == '#') {
                len *= 2;
            } else if (c == '%') {
                // Length doesn't change for reversal
            }
            lens.push_back(len);
        }
        
        // If k is out of bounds, return '.'
        if (k >= len) return '.';
        
        // k is already 0-indexed, so no conversion needed
        
        // Second pass: work backwards to find the character at position k
        // The idea is to reverse the operations and track where position k
        // would have been before each operation
        for (int i = s.size() - 1; i >= 0; --i) {
            char c = s[i];
            
            if (islower(c)) {
                // If this letter would be at position k, return it
                if (k == lens[i] - 1) return c;
                // No adjustment needed for letters in reverse simulation
                
            } else if (c == '*') {
                // No adjustment needed for '*' operation
                // Position k in string after '*' maps to position k in string before '*'
                
            } else if (c == '#') {
                // Map k back to original position before duplication
                // If k is in the second half, map it back to the first half
                long long half = lens[i] / 2;
                if (k >= half) k -= half;
                
            } else if (c == '%') {
                // Map k back to original position before reversal
                k = lens[i] - 1 - k;
            }
        }
        
        return '.';
    }
};