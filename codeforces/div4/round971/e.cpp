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

void solve() {
	ll n, k; cin >> n >> k;

	// o momento em que a soma dos suf eh mais prox da dos pre
	// bb pra achar ult neg

	auto pre = [&](int i) -> ll {
		return (ll)(k + k + i - 1) * i / 2;	
	};
	auto pos = [&](int i) -> ll {
		return (ll)(k + k + n - 1) * n / 2 - pre(i);	
	};

	int l = 1, r = n;
	while (l < r) {
		int m = (l+r) / 2;
		if (pre(m) > pos(m)) {
			r = m;	
		} else {
			l = m + 1;
		}
	}
	l--;
	
	ll res = abs(pos(l) - pre(l));
	for (int i = l; i <= n; i++) {
		res = min(res, abs(pos(i) - pre(i)));
		if (abs(pos(i) - pre(i)) < abs(pos(i+1) - pre(i+1))) break;
	}
	cout << res << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
