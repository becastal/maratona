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

int solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	vector<ll> res(n, 0), bit(n+2, 0);
	auto pref = [&](int x) {
		ll res = 0;
		for (int i = x+1; i; i-=i&-i) res += bit[i];
		return res;
	};
	auto query = [&](int l, int r) {
		return pref(r) - pref(l-1);
	};
	auto add = [&](int x) {
		for (int i = x+1; i <= n+1; i+=i&-i) bit[i]++;
	};

	for (int i = 0; i < n; i++) {
		res[A[i]+1] += query(A[i]+1, n);
		add(A[i]);
	}

	ll agr = 0;
	for (int i = 0; i < n; i++) {
		cout << (agr += res[i]) << endl;
	}

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main() {
    _;
	setIO("haircut");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}
