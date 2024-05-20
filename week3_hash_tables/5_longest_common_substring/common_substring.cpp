#include <iostream>
#include <vector>

using namespace std;

struct Answer {
    size_t i, j, len;
};

Answer solve(const string &s, const string &t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    Answer ans = {0, 0, 0};

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > ans.len) {
                    ans = {i - dp[i][j], j - dp[i][j], dp[i][j]};
                }
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    string s, t;
    while (cin >> s >> t) {
        auto ans = solve(s, t);
        cout << ans.i << " " << ans.j << " " << ans.len << "\n";
    }
}
