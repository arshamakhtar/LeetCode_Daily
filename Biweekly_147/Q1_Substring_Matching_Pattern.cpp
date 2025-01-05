class Solution {
public:
    bool hasMatch(string s, string p) {
        size_t star = p.find('*');
        string pre = p.substr(0, star), suf = p.substr(star + 1);
        size_t prePos = s.find(pre);
        if (prePos == string::npos) return false;
        size_t sufPos = s.find(suf, prePos + pre.length());
        return sufPos != string::npos && sufPos >= prePos + pre.length();
    }
};
