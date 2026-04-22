#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll


const int MAX = 1e6;
int divi[MAX];
vector<int> primes;

void crivo(int lim) {
	divi[1] = 1;
	for (int i = 2; i <= lim; i++) {
		if (divi[i] == 0) divi[i] = i, primes.push_back(i);
		for (int j : primes) {
			if (j > divi[i] or i*j > lim) break;
			divi[i*j] = j;
		}
	}
}

int solve() {
	int n; cin >> n;

	vector<int> Res(n, 1);
	for (int p = 0, pos = 0, ult = 1; p < (int)primes.size() and pos < n; p++) {
		int e = 1, base = primes[p];	
		while (__int128_t(1) * ult * base * primes[p] < __int128_t(1e18)) {
			base *= primes[p];	
			e++;
		}

		Res[pos++] = ult * base;
		for (int i = 1; i < e - 1 and pos < n; i++) {
			Res[pos++] = (base /= primes[p]);
		}

		ult = primes[p];
	}

	set<int> S;
	for (int i = 1; i < n; i++) { 
		S.insert(gcd(Res[i], Res[i-1]));
	}
	assert(S.size() == n-1);

	for (int i = 0; i < n; i++) {
		cout << Res[i] << " \n"[i==n-1];
	}

	return(0);
}

signed main()
{
    _;

	crivo(MAX - 1);

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

