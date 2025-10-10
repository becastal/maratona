#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
using namespace std;

vector<int> computeLIS(const vector<int>& v) {
    int n = v.size();
    vector<int> lis(n, 1);
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (v[i] > v[j])
                lis[i] = max(lis[i], lis[j] + 1);
    return lis;
}

vector<int> computeLDS(const vector<int>& v) {
    int n = v.size();
    vector<int> lds(n, 1);
    for (int i = n - 2; i >= 0; --i)
        for (int j = n - 1; j > i; --j)
            if (v[i] > v[j])
                lds[i] = max(lds[i], lds[j] + 1);
    return lds;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int& i : v) cin >> i;

    vector<int> lis = computeLIS(v);
    vector<int> lds = computeLDS(v);

    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, lis[i] + lds[i] - 1);
    }

    cout << res << endl;
}

int main() {
    _;
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
