#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int MAX = 100010;
int F[MAX], FF[MAX];

int solve() {
	int n, q; cin >> n >> q;
	int tam = ceil(sqrt(n));

	vector<int> A(n);
	for (int& i : A) cin >> i;

	vector<array<int, 3>> Q(q);
	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r;
		Q[i] = {l, r, i};
	}

	sort(all(Q), [&](auto& a, auto& b) {
		return make_pair(a[0] / tam, a[1]) < make_pair(b[0] / tam, b[1]);
	});

	vector<int> R(q);

	int res = 0;
	auto add = [&](int x) {
		--FF[F[A[x]]];
		FF[++F[A[x]]]++;

		if (res < F[A[x]]) res = F[A[x]];
	};

	auto remove = [&](int x) {
		--FF[F[A[x]]];
		FF[--F[A[x]]]++;

		while (res > 0 and !FF[res]) res--;
	};
	
	memset(F, 0, sizeof(F));
	int cl = 0, cr = -1;
	for (int i = 0; i < q; i++) {
		auto [l, r, id] = Q[i];

		while (cl > l) add(--cl);
		while (cr < r) add(++cr);
		while (cl < l) remove(cl++);
		while (cr > r) remove(cr--);
		R[id] = res;
	}

	for (int i : R) cout << i << endl;

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

