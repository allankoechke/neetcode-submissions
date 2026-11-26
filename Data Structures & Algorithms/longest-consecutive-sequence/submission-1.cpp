class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Create hash set from our data
        std::unordered_set<int> cache;
        for(const auto& num: nums) cache.insert(num);

        std::unordered_set<int> starter_vals{};
        for(const auto& num: nums) {
            if(!cache.contains(num-1)) 
                starter_vals.insert(num);
        }

        // For each starter val, build its seequence in a map;
        std::unordered_map<int, int> counts{};
        for(const auto& num: starter_vals) {
            int num_local = num;
            while(cache.contains(num_local)) {
                counts[num]++;
                num_local++;
            }
        }

        // for(const auto el: counts) std::cout << el.first << ": " << el.second << std::endl;

        auto max_it = std::max_element(
            counts.begin(), counts.end(), 
            [](const auto& a, const auto& b) { return a.second < b.second; }
        );

        return max_it != counts.end() ? max_it->second : 0;
    }
};
