class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mpp;
        for(int num : nums){
            mpp[num]++;            
        }
        vector<vector<int>> bucket(nums.size()+1) ;
        for(auto [num, freq]: mpp){
            bucket[freq].push_back(num);
        }
        vector<int>ans;
        for(int i = nums.size(); i>0; i--){
            if(k == 0) break;
            for(int el : bucket[i]){
                ans.push_back(el);
                k--;
                if(k == 0) return ans;
            }
            
        }
        return ans;
        
    }
};