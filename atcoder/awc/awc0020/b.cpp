#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m, s; cin >> n >> m >> s;
	vector<int> D(n), Rec(n);
	for (int& i : D) {
		cin >> i;
	}

	for (int i = 0, p, r; i < m; i++) {
		cin >> p >> r; p--;
		Rec[p] += r;
	}

	for (int i = 0, ex = 0; i < n; i++) {
		s -= D[i] + (ex ? D[i] : 0);
		ex |= s <= 0;
		s += Rec[i];
	}
	cout << s << endl;

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

