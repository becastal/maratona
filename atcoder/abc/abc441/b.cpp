#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;

	int t = 0, a = 0;
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		t |= (1 << (c - 'a'));
	}
	for (int i = 0; i < m; i++) {
		char c; cin >> c;
		a |= (1 << (c - 'a'));
	}

	int q; cin >> q;
	while (q--) {
		string Qi; cin >> Qi;

		int b = 0;
		for (char c : Qi) {
			b |= (1 << (c - 'a'));
		}

		int ta = (b & t) == b, aa = (b & a) == b;
		if (ta ^ aa) {
			cout << (ta ? "Takahashi" : "Aoki") << endl;
		} else {
			cout << "Unknown" << endl;
		}
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

