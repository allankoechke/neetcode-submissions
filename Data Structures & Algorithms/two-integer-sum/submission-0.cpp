class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Build a hashmap of key to index for O(1) query
        std::unordered_map<int, int> seen;
        int index = 0;
        for( const auto num : nums ) {
            // Check if diff exists in map, if so, return its index and the current index
            auto diff = target - num;
            if(seen.contains(diff)) {
                return {seen[diff], index};
            }

            // Store the seen number for future query
            seen.insert_or_assign(num, index);
            index++;
        }

        return {};
    }
};
