class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen;
        for(const auto& num: nums) {
            auto [_, added] = seen.insert(num);
            if(!added) return true;
        }
        return false;
    }
};