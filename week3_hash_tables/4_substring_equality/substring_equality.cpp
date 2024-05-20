#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ull;

class Solver {
    string s;
    vector<ull> p_hash; // Prefix hashes
    vector<ull> p_pow;  // Powers of the multiplier
    const ull prime = 1000000007;
    const ull multiplier = 263;

public:
    Solver(string s) : s(s) {
        int n = s.size();
        p_hash.resize(n + 1, 0);
        p_pow.resize(n + 1, 1);

        // Precompute hashes and powers of the multiplier
        for (int i = 0; i < n; ++i) {
            p_hash[i + 1] = (p_hash[i] * multiplier + s[i]) % prime;
            p_pow[i + 1] = (p_pow[i] * multiplier) % prime;
        }
    }

    bool ask(int a, int b, int l) {
        ull hash_a = (p_hash[a + l] + prime - (p_hash[a] * p_pow[l]) % prime) % prime;
        ull hash_b = (p_hash[b + l] + prime - (p_hash[b] * p_pow[l]) % prime) % prime;
        return hash_a == hash_b;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    string s;
    int q;
    cin >> s >> q;
    Solver solver(s);
    for (int i = 0; i < q; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
    }
}
