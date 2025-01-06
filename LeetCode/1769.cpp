class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> ans(n, 0);
        
        // Left-to-right pass
        int balls = 0, moves = 0;
        for (int i = 0; i < n; ++i) {
            ans[i] += moves;
            balls += (boxes[i] == '1') ? 1 : 0;
            moves += balls;
        }
        
        // Right-to-left pass
        balls = 0, moves = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] += moves;
            balls += (boxes[i] == '1') ? 1 : 0;
            moves += balls;
        }
        
        return ans;
    }
};
