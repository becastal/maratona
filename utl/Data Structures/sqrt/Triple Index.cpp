#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int MAX = 2e5+10;
int F[MAX];

int solve() {
	int n, q; cin >> n >> q;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	vector<array<int, 3>> Q(q);
	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r; l--, r--;
		Q[i] = {l, r, i};
	}

	int tam = ceil(sqrt(n));
	sort(all(Q), [&](auto& a, auto& b) {
		return make_pair(a[0] / tam, a[1]) < make_pair(b[0] / tam, b[1]);
	});

	memset(F, 0, sizeof(F));
	ll res = 0;

	auto c3 = [&](ll x) -> ll {
		if (x < 3) return 0;
		return x * (x - 1) * (x - 2) / 6;
	};

	auto add = [&](int i) {
		res -= c3(F[A[i]]);
		res += c3(++F[A[i]]);
	};
	auto rem = [&](int i) {
		res -= c3(F[A[i]]);
		res += c3(--F[A[i]]);
	};
	
	vector<ll> R(q);
	int agrl = 0, agrr = -1;
	for (auto [l, r, id] : Q) {
		while (agrr < r) add(++agrr);
		while (agrl > l) add(--agrl);
		while (agrl < l) rem(agrl++);
		while (agrr > r) rem(agrr--);
		R[id] = res;	
	}
	for (ll i : R) cout << i << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

