class Solution
{
public:
    int minChar(string &s)
    {
        long long a = 0, b = 0, d = 1, ans = INT_MAX, MOD = 1e9 + 7, D = 998857;
        for (int i = 0, n = s.size(); i < n; i++)
        {
            a = (a * D + s[i]) % MOD;
            b = (b + s[i] * d) % MOD;
            if (a == b)
                ans = min(ans, n - i - 1ll);
            d = (d * D) % MOD;
        }
        return ans;
    }
};
