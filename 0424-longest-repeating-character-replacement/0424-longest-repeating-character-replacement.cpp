class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int l = 0;
        int mostFreq = 0; // majority
        int maxLen = 0;
        for (int r = 0; r < s.size(); r++) {
            count[s[r] - 'A']++;
            mostFreq = max(mostFreq, count[s[r] - 'A']);
            // WHILE (INVALID WINDOW)
            // int currSize = r - l + 1;
            // int toBeReplaced = currSize - mostFreq;
            while ((r - l + 1) - mostFreq > k) {
                count[s[l] - 'A']--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};