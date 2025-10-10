#include <bits/stdc++.h>
// Otimizacoes agressivas, pode deixar mais rapido ou mais devagar
#pragma GCC optimize("Ofast")
// Auto explicativo
#pragma GCC optimize("unroll-loops")
// Vetorizacao
#pragma GCC target("avx2")
// Para operacoes com bits
#pragma GCC target("bmi,bmi2,popcnt,lzcnt")
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
	map<int, set<int>> FF;

	vector<int> B(A);
	sort(all(B));
	B.erase(unique(all(B)), B.end());
	for (int& i : A) {
		i = lower_bound(all(B), i) - B.begin();
		FF[0].insert(i);
	}

	vector<array<int, 3>> Q(q);
	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r; l--, r--;
		Q[i] = {l, r, i};
	}

	int tam = ceil(sqrt(n));
	sort(all(Q), [&tam](auto& a, auto& b) {
		if (a[0] / tam != b[0] / tam) return a[0] < b[0];
		if ((a[0] / tam) % 2) return a[1] > b[1];
		return a[1] < b[1];
	});

	auto add = [&](int a) {
		FF[F[a]].erase(a);
		if (FF[F[a]].empty()) FF.erase(F[a]);
		FF[++F[a]].insert(a);
	};
	auto rem = [&](int a) {
		FF[F[a]].erase(a);
		if (FF[F[a]].empty()) FF.erase(F[a]);
		FF[--F[a]].insert(a);
	};
	auto calc = [&](int l, int r) {
		vector<int> Ri;
		auto it = FF.rbegin();

		for (auto it = FF.rbegin(); it != FF.rend(); it++) {
			auto [f, S] = *it;
			if (f <= (r - l + 1) / 3) break;
			for (auto& i : S) Ri.push_back(i);
		}
		// da pra melhorar usando map talvez
		//vector<int> Ri;
		//for (int i = r - l + 1; i > (r - l + 1) / 3; i--) {
		//	for (auto j : FF[i]) {
		//		Ri.push_back(j);
		//	}
		//}
		sort(all(Ri));

		return Ri;
	};

	vector<vector<int>> R(q);
	int cl = 0, cr = -1;
	for (auto [l, r, id] : Q) {
		while (cr < r) add(A[++cr]);
		while (cl > l) add(A[--cl]);
		while (cr > r) rem(A[cr--]);
		while (cl < l) rem(A[cl++]);
		R[id] = calc(l, r);
	}

	for (int i = 0; i < q; i++) {
		if (R[i].empty()) {
			cout << -1 << endl;
			continue;
		}

		for (int j : R[i]) {
			cout << B[j] << ' ';
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++) {
		F[A[i]] = 0;
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

