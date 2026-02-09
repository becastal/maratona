#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const ll pot = 696969;
const ll mod = 1e9+9;

int solve() {
	int n; cin >> n;
	vector<int> A(n), B(n);

	for (int& i : A) cin >> i;
	for (int& i : B) cin >> i;

	
	vector<ll> Pa(n), Pb(n);

	auto base = [&](int e) {
		ll ret = 1, b = pot;
		while (e) {
			if (e % 2) ret = ret * b % mod;
			e /= 2, b = b * b % mod;
		}
		return ret;
	};
	// base(a) tem que retornar pot ^ a.

	set<int> S;
	for (int i = 0, p = 0; i < n; i++) {
		if (!S.count(A[i])) {
			p = (p + base(A[i])) % mod;
		}
		Pa[i] = p;
		S.insert(A[i]);
	}
	S.clear();

	for (int i = 0, p = 0; i < n; i++) {
		if (!S.count(B[i])) {
			p = (p + base(B[i])) % mod;
		}
		Pb[i] = p;
		S.insert(B[i]);
	}

	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b; a--, b--;
		cout << (Pa[a] == Pb[b] ? "Yes" : "No") << endl;
	}
	

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

