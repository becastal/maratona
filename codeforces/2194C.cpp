#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

vector<int> divs(int a) {
	vector<int> r;
	for (int i = 1; i * i <= a; i++) {
		if (a % i == 0) {
			r.push_back(i);
			if (a / i != i) r.push_back(a / i);
		}
	}
	sort(all(r));
	return r;
}

int solve() {
	int n, k; cin >> n >> k;

	vector<int> vis(n);
	vector<string> A(k);
	for (auto& s : A) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			vis[j] |= (1 << (s[j] - 'a'));
		}
	}

	for (int d : divs(n)) {
		string res = "";
		int ok = 1;
		for (int p = 0; p < d and ok; p++) {
			int agr = LLONG_MAX;
			for (int i = p; i < n; i += d) {
				agr &= vis[i];	
			}
			if (!agr) ok = 0;
			else {
				//res.push_back(char('a' +  __builtin_ctz(agr) + 1));
				res.push_back(char('a' +  __builtin_ctz(agr & -agr)));
			}
		}

		if (ok) {
			for (int i = 0; i < n / d; i++) {
				cout << res;	
			}
			cout << endl;
			return 0;
		}
	}
	assert(0);

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

