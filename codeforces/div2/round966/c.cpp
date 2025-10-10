#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

void solve() {
	int n, m; cin >> n >> m;
	string s; cin >> s;

	vector a(n, vector<ll>(m)), b(n, vector<ll>(m));

	for (auto& l : a) for (auto& c : l) cin >> c;
	b = a;

	int ii = 0, jj = 0;


	ll obj = 0;
	ll lin = 0, col = 0;
	for (int i = 0; i < n + m - 1; i++) {
		if (s[i] == 'D') {
			ll agr = obj;
			for (int j = 0; j < m; j++) {
				agr -= b[ii][j];	
			}
			b[ii++][jj] = agr;
		} else {
			ll agr = obj;
			for (int j = 0; j < n; j++) {
				agr -= b[j][jj];
			}
			b[ii][jj++] = agr;
		}
	}

	for (auto l : a) {
		for (auto c : l) {
			cout << setw(4) << c << ' ';
		}
		cout << endl;
	}
	cout << endl << endl;

	for (auto l : b) {
		for (auto c : l) {
			cout << setw(4) << c << ' ';
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++) {
		int si = 0;
		for (int j = 0; j < m; j++) {
			si += b[i][j];
		}
		cout << si << ' ';
	}
	cout << endl;
	for (int i = 0; i < m; i++) {
		int si = 0;
		for (int j = 0; j < n; j++) {
			si += b[j][i];
		}
		cout << si << ' ';
	}
	cout << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
