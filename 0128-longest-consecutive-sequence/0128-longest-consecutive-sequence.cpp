class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int maxlen = 0;
        for (int num : seen) {
            if (seen.count(num - 1))
                continue;
            int len = 0;
            while (seen.count(num)) {
                len++;
                num++;
            }
            maxlen = max(maxlen, len);
        }
        return maxlen;
    }
};