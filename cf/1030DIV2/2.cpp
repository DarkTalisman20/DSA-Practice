#include<bits/stdc++.h>
using namespace std;

void fn() {
    int n; cin >> n;
    vector<tuple<int, int, int>> res;
    for (int i = 1; i < n; i++) {
        res.emplace_back(i, i, n);
    }
    for (int i = 2; i <= n; i++) {
        if (i - 1 == n) continue;
        if (1 != i - 1)
            res.emplace_back(i, 1, i - 1);
    }
    cout << res.size() << endl;
    for (auto x : res) {
        int a, b, c;
        tie(a, b, c) = x;
        cout << a << " " << b << " " << c << endl;
    }
}

int main() {
    int t = 1; cin >> t;
    while (t--) {
        fn();
    }
    return 0;
}
