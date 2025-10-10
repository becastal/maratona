#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int MAX = (1 << 20) + 10;
int F[MAX];
int solve() {
	int n, q, k; cin >> n >> q >> k;

	memset(F, 0, sizeof(F));
	vector<int> A(n);
	for (int& i : A) cin >> i;

	vector<int> P(n+1, 0);
	for (int i = 1; i <= n; i++) {
		P[i] = P[i-1] ^ A[i-1];	
	}

	vector<array<int, 3>> Q(q);
	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r; l--;
		Q[i] = {l, r, i};
	}

	int tam = ceil(sqrt(n));
	sort(all(Q), [&](auto a, auto b) {
		return make_pair(a[0] / tam, a[1]) < make_pair(b[0] / tam, b[1]);
	});

	ll res = 0;
	auto add = [&](int i) {
		res += F[P[i] ^ k];	
		F[P[i]]++;
	};
	auto rem = [&](int i) {
		F[P[i]]--;
		res -= F[P[i] ^ k];
	};

	vector<ll> R(q);
	int agrl = 0, agrr = -1;
	for (auto [l, r, id] : Q) {
		while (agrl > l) add(--agrl);
		while (agrr < r) add(++agrr);
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

