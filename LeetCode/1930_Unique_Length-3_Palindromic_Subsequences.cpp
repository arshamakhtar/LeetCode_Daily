class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);
        unordered_set<string> uniquePalindromes;

        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }

        for (int c = 0; c < 26; c++) {
            if (first[c] != -1 && last[c] != -1 && first[c] < last[c]) {
                unordered_set<char> middleChars;
                for (int i = first[c] + 1; i < last[c]; i++) {
                    middleChars.insert(s[i]);
                }
                for (char mid : middleChars) {
                    uniquePalindromes.insert(string(1, c + 'a') + mid + string(1, c + 'a'));
                }
            }
        }

        return uniquePalindromes.size();
    }
};

