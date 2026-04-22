#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, q; cin >> n >> q;
	vector<string> A(n);
	for (auto& i : A) {
		cin >> i;
	}

	vector<int> C(26);
	iota(all(C), 0);

	for (int qi = 0; qi < q; qi++) {
		char a, b; cin >> a >> b;
		for (int i = 0; i < 26; i++) {
			if (C[i] == a - 'a') {
				C[i] = b - 'a';
			}
		}
	}

	for (string& s : A ) {
		for (char c : s) {
			cout << char('a' + C[c - 'a']);
		}
		cout << endl;
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

