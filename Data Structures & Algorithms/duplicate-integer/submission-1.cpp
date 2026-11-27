class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // std::set
        // std::unordered_set
        std::unordered_set<int> cache;

        for(const auto& num: nums) {
            auto [_, added] = cache.insert(num);
            if(!added) return true;
        }

        return false;
    }
};