class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;

        while (start < end) {
            // Skip non-alphanumeric characters
            while (start < end && !isalnum(s[start])) start++;
            while (start < end && !isalnum(s[end]))   end--;

            // Compare ignoring case
            if (tolower(s[start]) != tolower(s[end]))
                return false;

            start++;
            end--;   // ✅ move inward
        }
        return true;
    }
};