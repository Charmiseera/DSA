1class Solution {
2public:
3    static const int MOD = 1e9 + 7;
4
5    int subsequencePairCount(vector<int>& nums) {
6        const int MAX = 200;
7
8        vector<vector<long long>> dp(MAX + 1, vector<long long>(MAX + 1, 0));
9        dp[0][0] = 1;
10
11        for (int x : nums) {
12            vector<vector<long long>> ndp = dp;
13
14            for (int g1 = 0; g1 <= MAX; g1++) {
15                for (int g2 = 0; g2 <= MAX; g2++) {
16                    long long ways = dp[g1][g2];
17                    if (!ways) continue;
18
19                    int ng1 = (g1 == 0) ? x : gcd(g1, x);
20                    ndp[ng1][g2] = (ndp[ng1][g2] + ways) % MOD;
21
22                    int ng2 = (g2 == 0) ? x : gcd(g2, x);
23                    ndp[g1][ng2] = (ndp[g1][ng2] + ways) % MOD;
24                }
25            }
26
27            dp.swap(ndp);
28        }
29
30        long long ans = 0;
31
32        for (int g = 1; g <= MAX; g++)
33            ans = (ans + dp[g][g]) % MOD;
34
35        return (int)ans;
36    }
37};