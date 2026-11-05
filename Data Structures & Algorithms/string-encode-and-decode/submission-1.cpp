class Solution {
public:

    string encode(vector<string>& strs) {
        string res{};

        for(const auto& str : strs) {
            auto len = str.size();
            res += format("#{}:{}", len, str);
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res{};

        int index = 0;
        while(index < s.size()){
            auto c = s[++index]; // Start consuming chars
            string len_str{};
            while(c != ':') {
                len_str += c;
                c = s[++index];
            }

            int len = stoi(len_str);
            auto portion = s.substr(index+1, len);
            res.push_back(portion);

            // Increment index
            ++index += len;
        }

        return res;
    }
};
