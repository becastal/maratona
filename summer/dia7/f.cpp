#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

const ll P = 69420;
const ll M = 1e9+9;

int main()
{
    _;

    string s; cin >> s;
    int n = (int)s.size();

    vector<ll> base(n+1), pre(n+1);
    base[0] = 1;
    for (int i = 1; i <= n; i++) {
        base[i] = base[i - 1] * P % M;
    }

    for (int i = 1; i <= n; i++) {
        pre[i] = (pre[i - 1] * P + s[i - 1]) % M;
    }

    auto hash = [&] (int l, int r) -> ll {
        ll h = (pre[r + 1] - base[r - l + 1] * pre[l] % M + M) % M;
        return h;
    };

    vector<int> p(n, 0);
    for (int i = 1, j = 0; i < n; i++) {
        while (j and s[j] != s[i]) j = p[j-1];
        if (s[j] == s[i]) j++;
        p[i] = j;
    }

    vector<int> cont(n+1, 0);
    for (int i = 0; i < n; i++) {
        cont[p[i]]++;
    }

    for (int i = n-1; i > 0; i--) {
        cont[p[i-1]] += cont[i];
    }

    for (int i = 1; i <= n; i++) {
        cont[i]++;
    }

	vector<pair<int, int>> res;
    for (int i = 1; i <= n; i++) {
        if (hash(0, i-1) == hash(n-i, n-1)) {
			res.emplace_back(i, cont[i]);
        }
    }

	cout << res.size() << endl;
	for (auto [a, b] : res) cout << a << ' ' << b << endl;

    return 0;
}

