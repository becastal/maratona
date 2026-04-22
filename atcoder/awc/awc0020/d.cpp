#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, l; cin >> n >> l;

	vector<array<int, 2>> Ev;
	for (int i = 0, x, r; i < n; i++) {
		cin >> x >> r;
		Ev.push_back({max(0LL, x - r), 0});	
		Ev.push_back({min(l, x + r), 1});	
	}
	sort(all(Ev));

	int cont = 0, agr = 0, ult = 0;
	for (auto [p, tp] : Ev) {
		if (agr) {
			cont += p - ult;
		}
		agr += (tp ? -1 : +1);
		ult = p;
	}
	cout << (cont == l ? "Yes" : "No") << endl;

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

