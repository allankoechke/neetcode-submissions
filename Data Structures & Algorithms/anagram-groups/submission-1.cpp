class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<vector<string>> res; // Result vector
        std::unordered_map<string, vector<string>> store; // Store key - val pairs

        for(const string& str : strs) {
            auto key = str;
            std::sort(key.begin(), key.end()); // Sort str to be keys
            store[key].push_back(str); // Add key and append string to vector
        }

        // Join all vectors generated earlier
        for(const auto& [_,vec] : store) {
            res.push_back(vec);
        }

        return res;
    }
};
