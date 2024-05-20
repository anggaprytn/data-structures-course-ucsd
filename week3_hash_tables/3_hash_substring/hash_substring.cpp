#include <iostream>
#include <string>
#include <vector>

using std::string;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

ull hash_func(const string& s, const ull prime, const ull multiplier) {
    ull hash = 0;
    for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i)
        hash = (hash * multiplier + s[i]) % prime;
    return hash;
}

std::vector<int> get_occurrences(const Data& input) {
    const string& pattern = input.pattern;
    const string& text = input.text;
    const ull prime = 1000000007;
    const ull multiplier = 263;

    std::vector<int> occurrences;
    size_t p_len = pattern.size(), t_len = text.size();

    if (p_len > t_len) return occurrences;

    ull pattern_hash = hash_func(pattern, prime, multiplier);
    ull current_hash = hash_func(text.substr(0, p_len), prime, multiplier);

    // Precompute the highest power of multiplier mod prime
    ull highest_multiplier = 1;
    for (size_t i = 0; i < p_len - 1; ++i) {
        highest_multiplier = (highest_multiplier * multiplier) % prime;
    }

    for (size_t i = 0; i <= t_len - p_len; ++i) {
        if (pattern_hash == current_hash && text.substr(i, p_len) == pattern) {
            occurrences.push_back(i);
        }
        if (i < t_len - p_len) {
            current_hash = (current_hash + prime - text[i] * highest_multiplier % prime) % prime;
            current_hash = (current_hash * multiplier + text[i + p_len]) % prime;
        }
    }

    return occurrences;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
