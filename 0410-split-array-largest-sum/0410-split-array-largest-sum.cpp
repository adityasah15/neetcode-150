class Solution {
public:
    int possible(vector<int>& nums, int k, long long maxsize) {
        long long currsize = 0;
        int grp = 1;
        for (int num : nums) {
            if (currsize + num > maxsize) {
                currsize = num;
                grp++;
            } else {
                currsize += num;
            }
            if (grp > k)
                return false;
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (possible(nums, k, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};