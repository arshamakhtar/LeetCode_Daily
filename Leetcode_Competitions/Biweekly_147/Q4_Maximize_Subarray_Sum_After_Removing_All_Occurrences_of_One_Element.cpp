class Solution {
public:
    long long a[400005], b[400005], s[400005], lz[400005];
    int n, v[100005];
    void down(int x){
        if(lz[x] == 0) return ;
        lz[x * 2] += lz[x];
        lz[x * 2 + 1] += lz[x];
        a[x * 2] += lz[x];
        a[x * 2 + 1] += lz[x];
        b[x * 2] += lz[x];
        b[x * 2 + 1] += lz[x];
        lz[x] = 0;
        return ;
    }
    void up(int x){
        a[x] = std::min(a[x * 2], a[x * 2 + 1]);
        b[x] = std::max(b[x * 2], b[x * 2 + 1]);
        s[x] = std::max(s[x * 2], s[x * 2 + 1]);
        s[x] = std::max(s[x], b[x * 2 + 1] - a[x * 2]);
        return ;
    }
    void upd(int x, int l, int r, int L, int R, int y){
        if(L == l && r == R){
            a[x] += y;
            b[x] += y;
            lz[x] += y;
            return ;
        }
        down(x);
        int mid = l + r >> 1;
        if(R <= mid) upd(x * 2, l, mid, L, R, y);
        else if(L >= mid + 1) upd(x * 2 + 1, mid + 1, r, L, R, y);
        else {
            upd(x * 2, l, mid, L, mid, y);
            upd(x * 2 + 1, mid + 1, r, mid + 1, R, y);
        }
        up(x);
        return ;
    }
    long long ask(){
        return s[1];
    }
    struct val{
        int x, y;
    }t[100005];
    long long maxSubarraySum(vector<int>& nums) {
        n = nums.size();
        for(int i = 0; i < n; ++i) v[i + 1] = nums[i], t[i + 1].x = i + 1, t[i + 1].y = nums[i];
        bool flag = true;
        for(int i = 0; i < n; ++i) if(nums[i] > 0) flag = false;
        if(flag == true){
            long long mx = nums[0];
            for(int i = 1; i < n; ++i) mx = std::max(mx, 1ll * nums[i]);
            return mx;
        }
        for(int i = 1; i <= n; ++i) upd(1, 0, n, i, n, v[i]);
        long long ans = ask();
        std::sort(t + 1, t + n + 1, [&](val a, val b){
            return a.y < b.y;
        });
        for(int i = 1, j; i <= n; i = j + 1){
            j = i;
            while(j < n && t[j + 1].y == t[j].y) ++j;
            for(int k = i; k <= j; ++k) upd(1, 0, n, t[k].x, n, -t[k].y);
            ans = std::max(ans, ask());
            for(int k = i; k <= j; ++k) upd(1, 0, n, t[k].x, n, t[k].y);
        }
        return ans;
    }
};
