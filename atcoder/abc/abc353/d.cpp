#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int mod = 998244353;
int solve() {
	int n; cin >> n;

	vector<int> P(11, 1), C(11);
	for (int i = 1; i < 11; i++) { 
		P[i] = P[i-1] * 10 % mod;
	}


	auto tam = [&](int a) {
		int res = 0;
		while (a) {
			a /= 10;	
			res++;
		}
		return res;
	};

	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	int res = 0;
	for (int i = n-1; i >= 0; i--) {
		int a = A[i];
		res += i * a % mod;
		if (res >= mod) {
			res -= mod;
		}

		for (int t = 1; t <= 10; t++) {
			res += P[t] * a % mod * C[t] % mod;
			if (res >= mod) {
				res -= mod;
			}
		}

		C[tam(a)]++;
	}
	cout << res << endl;

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

