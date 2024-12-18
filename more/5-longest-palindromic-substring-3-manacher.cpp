// O(n)

class Solution {
public:
    string longestPalindrome(std::string s) {
        if (s.length() <= 1) return s;
        
        // Preprocess the string with '#' characters to handle even-length palindromes
        string modified_s = "#";
        for (char c : s) {
            modified_s += c;
            modified_s += '#';
        }

        int n = modified_s.size();
        vector<int> dp(n, 0); // dp array to store the radius of the palindrome centered at each character
        int center = 0, right = 0; // Initialize center and right boundary
        int max_len = 1; // Maximum length of palindrome found
        string max_str = s.substr(0, 1); // Initialize the max palindrome substring with the first character
        
        for (int i = 0; i < n; i++) {
            // If i is within the current right boundary, use previously calculated values to minimize comparisons
            if (i < right) {
                dp[i] = min(right - i, dp[2 * center - i]);
            }
            
            // Expand around center i
            while (i - dp[i] - 1 >= 0 && i + dp[i] + 1 < n && modified_s[i - dp[i] - 1] == modified_s[i + dp[i] + 1]) {
                dp[i]++;
            }
            
            // Update center and right boundary if we've expanded beyond the current right
            if (i + dp[i] > right) {
                center = i;
                right = i + dp[i];
            }
            
            // Update max_len and max_str if a longer palindrome is found
            if (dp[i] > max_len) {
                max_len = dp[i];
                max_str = modified_s.substr(i - dp[i], 2 * dp[i] + 1);
                max_str.erase(remove(max_str.begin(), max_str.end(), '#'), max_str.end());
            }
        }
        
        return max_str;
    }
};
