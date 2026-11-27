class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        std::unordered_map<char, int> _smap, _tmap;

        for(auto c: s) _smap[c]++; // _map[c] = 0;
        for(auto c: t) _tmap[c]++; // _map[c] = 0;

        return _smap == _tmap;
    }
};
