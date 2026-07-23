class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int maxcount = 0;
        for (int num : seen) {
            int count = 0;
            if (seen.count(num - 1))
                continue;
            int i = 0;
            while (seen.count(num + i)) {
                count++;
                i++;
            }
            maxcount = max(maxcount, count);
        }
        return maxcount;
    }
};