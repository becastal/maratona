#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int solve() {
	int n; cin >> n;
	vector<int> A(n), B(n);

	map<int, int> M;
	for (int& i : A) {
		cin >> i;
		if (!M.count(i)) {
			M[i] = uniform(1, 1000000000000000000LL);
		}
		i = M[i];
	}

	for (int& i : B) {
		cin >> i;
		if (!M.count(i)) {
			M[i] = uniform(1, 1000000000000000000LL);
		}
		i = M[i];
	}

	vector<int> Pa(n), Pb(n);
	set<int> S;

	for (int i = 0; i < n; i++) {
		if (i) Pa[i] = Pa[i-1];
		if (!S.count(A[i])) {
			Pa[i] ^= A[i];
		}
		S.insert(A[i]);
	}

	S.clear();
	for (int i = 0; i < n; i++) {
		if (i) Pb[i] = Pb[i-1];
		if (!S.count(B[i])) {
			Pb[i] ^= B[i];
		}
		S.insert(B[i]);
	}

	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b; a--, b--;
		cout << (Pa[a] == Pb[b] ? "Yes" : "No") << endl;
	}

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

