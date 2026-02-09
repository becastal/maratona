#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
	bb pra achar cada um dos indices comparando query normal com query da modificada
*/

int solve() {
	int n; cin >> n;

	auto query = [](int tp, int l, int r) {
		cout << tp << ' ' << l+1 << ' ' << r+1 << endl;
		ll s; cin >> s;
		return s;
	};

	int l = 0, r = n-1, resl = r;
	while (l <= r) {
		int m = l + (r - l) / 2;	

		if (query(1, 0, m) != query(2, 0, m)) {
			r = m-1;
			resl = m;
		} else {
			l = m+1;	
		}
	}

	ll s = query(2, 0, n-1);
	int tam = s - 1LL * n * (1 + n) / 2;
	cout << "! " << resl+1 << ' ' << resl+tam << endl;

	return(0);
}

int main()
{
    //_;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

