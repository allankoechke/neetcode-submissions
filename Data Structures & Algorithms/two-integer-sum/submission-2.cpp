class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> cache;

        for(int i=0; i<nums.size(); i++) {
            auto num = nums[i];
            auto diff = target-num;

            if(cache.contains(diff)) {
                return {cache[diff], i};
            }

            cache[num] = i;
        }

        return {};
    }
};
