class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        std::unordered_map<char, int> _smap, _tmap;

        for(char c: s) _smap[c]++;
        for(char c: t) _tmap[c]++;

        return _smap == _tmap;
    }
};
