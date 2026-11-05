class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        // Count char's
        std::unordered_map<char, int> s_counter, t_counter;

        // Counter for s
        for(const auto c : s) {
            s_counter[c]++;
        }

        // Counter for t
        for(const auto c : t) {
            t_counter[c]++;
        }

        return s_counter == t_counter;
    }
};
