class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }

        unordered_map<char, int> mp;
        for (int i = 0; i < t.size(); i++) {
            mp[t[i]]++;  // Count frequency of characters in t
        }

        int count = 0;  // To track how many characters from t are matched
        int left = 0;
        int min_length = INT_MAX;
        int min_start = 0;

        // Loop through s to find the minimum window
        for (int right = 0; right < s.size(); right++) {
            // Decrease the count for current character in s
            if (mp[s[right]] > 0) {
                count++;
            }
            mp[s[right]]--;  // Decrease the frequency of the current character

            // When count matches the length of t, check the window
            if (count == t.size()) {
                // Try to shrink the window from the left
                while (left <= right && mp[s[left]] < 0) {
                    mp[s[left]]++;  // Restore the character at left
                    left++;  // Shrink from left
                }

                // Update the minimum window length
                if (right - left + 1 < min_length) {
                    min_length = right - left + 1;
                    min_start = left;
                }

                // Move left pointer forward and decrease count
                mp[s[left]]++;
                left++;
                count--;
            }
        }

        // If no valid window is found, return an empty string
        return min_length == INT_MAX ? "" : s.substr(min_start, min_length);
    }
};
