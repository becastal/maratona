#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int solve() {
	int n, q; cin >> n >> q;

	vector<int> A(n);
	for (int& i : A) cin >> i;
	auto B = A;

	sort(all(B));
	B.erase(unique(all(B)), B.end());
	
	vector<vector<int>> P(n);
	for (int i = 0; i < n; i++) {
		A[i] = lower_bound(all(B), A[i]) - B.begin();
		P[A[i]].push_back(i);
	}

	while (q--) {
		int l, r; cin >> l >> r; l--, r--;

		vector<int> R;
		for (int t = 0; t < 100; t++) {
			int p = uniform(l, r);
			int cont = upper_bound(all(P[A[p]]), r) - lower_bound(all(P[A[p]]), l);
			if (cont > (r - l + 1) / 3) R.push_back(A[p]);
		}

		sort(all(R));
		R.erase(unique(all(R)), R.end());
		for (int& i : R) i = B[i];

		if (R.empty()) cout << -1 << endl;
		else for (int i : R) cout << i << ' '; cout << endl;
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

