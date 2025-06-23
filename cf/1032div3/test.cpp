#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    string s1_str, s2_str;
    cin >> s1_str >> s2_str;

    vector<long long> pos1, pos2;
    for (int j = 0; j < n; ++j) {
        if (s1_str[j] == '1') {
            pos1.push_back(j + 1);
        }
        if (s2_str[j] == '1') {
            pos2.push_back(j + 1);
        }
    }

    vector<long long> pref_sum1(pos1.size() + 1, 0);
    for (size_t j = 0; j < pos1.size(); ++j) {
        pref_sum1[j + 1] = pref_sum1[j] + pos1[j];
    }

    vector<long long> pref_sum2(pos2.size() + 1, 0);
    for (size_t j = 0; j < pos2.size(); ++j) {
        pref_sum2[j + 1] = pref_sum2[j] + pos2[j];
    }
    
    long long min_ops = -1;

    for (int k = 1; k <= n; ++k) {
        long long needed1 = k;
        long long needed2 = n - k + 1;

        if (pos1.size() < needed1 || pos2.size() < needed2) {
            continue;
        }

        long long initial_sum1 = pref_sum1[needed1];
        long long target_sum1 = needed1 * (needed1 + 1) / 2;
        long long cost1 = initial_sum1 - target_sum1;

        long long initial_sum2 = pref_sum2.back() - pref_sum2[pos2.size() - needed2];
        long long sum_to_n = (1LL * n * (n + 1)) / 2;
        long long sum_to_k_minus_1 = (1LL * (k - 1) * k) / 2;
        long long target_sum2 = sum_to_n - sum_to_k_minus_1;
        long long cost2 = target_sum2 - initial_sum2;

        long long current_ops = cost1 + cost2;

        if (min_ops == -1 || current_ops < min_ops) {
            min_ops = current_ops;
        }
    }

    cout << min_ops << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
