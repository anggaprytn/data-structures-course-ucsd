#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> solve(int k, const string &text, const string &pattern) {
    vector<int> pos;
    int t_len = text.size();
    int p_len = pattern.size();

    for (int i = 0; i <= t_len - p_len; ++i) {
        int mismatches = 0;
        for (int j = 0; j < p_len; ++j) {
            if (text[i + j] != pattern[j]) {
                mismatches++;
                if (mismatches > k) {
                    break;
                }
            }
        }
        if (mismatches <= k) {
            pos.push_back(i);
        }
    }
    return pos;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int k;
    string t, p;
    while (cin >> k >> t >> p) {
        auto a = solve(k, t, p);
        cout << a.size();
        for (int x : a)
            cout << " " << x;
        cout << "\n";
    }
}
