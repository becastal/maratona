#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	ll n, p; cin >> n >> p;

	vector<int> primo(p+1, 1), P;

	for (int i = 2; i <= p; i++) if (primo[i]) {
		P.push_back(i);
		for (int j = i + i; j <= p; j += i) {
			primo[j] = 0;
		}
	}
	
	auto gera = [&](vector<ll>& A, ll pri) {
		int mm = (int)A.size();
		for (int i = 0; i < mm; i++) {
			ll pi = A[i];
			while (1) {
				pi *= pri;
				if (pi > n) break;
				A.push_back(pi);
			}
		}
	};

	vector<ll> A = {1}, B = {1};
	for (int i : P) {
		if (A.size() < B.size()) gera(A, i);
		else gera(B, i);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	ll res = 0;
	for (int i = 0, j = (int)B.size() - 1; i < (int)A.size(); i++) {
		ll mv = (n / A[i]);
		while (j > 0 and mv < B[j]) {
			j--;
		}
		if (j < 0) break;
		res += (j + 1);
	}
	cout << res << endl;

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

