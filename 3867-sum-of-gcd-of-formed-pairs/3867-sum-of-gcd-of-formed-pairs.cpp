class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    long long gcdSum(vector<int>& nums) {
        int mx = nums[0];
        vector<int> prefixGcd(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(mx, nums[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long sum = 0;
        int i = 0;
        int j = prefixGcd.size() - 1;
        while (i < j) {
            sum += gcd(prefixGcd[i++], prefixGcd[j--]);
        }
        return sum;
    }
};