#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int MAX = 1e6+10;
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

	int impares = 0;
	auto add = [&](int i) {
		if (F[A[i]]) impares--;
		else impares++;
		F[A[i]] ^= 1;
	};

	vector<int> R(q);
	memset(F, 0, sizeof(F));
	int agrl = 0, agrr = -1;
	for (auto [l, r, id] : Q) {
		while (agrl > l) add(--agrl);
		while (agrl < l) add(agrl++);
		while (agrr > r) add(agrr--);
		while (agrr < r) add(++agrr);
		R[id] = !impares;
	}
	for (int i : R) {
		cout << (i ? "YES" : "NO") << endl;
	}

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

