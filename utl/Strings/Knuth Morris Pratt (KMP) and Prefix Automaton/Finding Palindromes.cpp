#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

vector<int> get_z(string s) {
	int n = s.size();
	vector<int> z(n, 0);

	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}

	return z;
}

int solve() {
	int n; cin >> n;

	vector<int> N(n);
	vector<string> A(n);

	map<string, int> C;

	auto root = [](string& s) {
		int nn = (int)s.size();
		vector<int> p(nn);

		for (int i = 1, j = 0; i < nn; i++) {
			while (j and s[j] != s[i]) j = p[j-1];
			p[i] = (j += s[i] == s[j]);
		}

		int t = p[nn-1];
		if (t and nn % (nn - t) == 0) return s.substr(0, nn - t);
		return s;
	};

	int res = 0;
	for (int i = 0; i < n; i++) {
		cin >> N[i] >> A[i];
		res += C[root(A[i])]++;
	}

	res = 2 * res + n;
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

