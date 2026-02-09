#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int w, h, n; cin >> w >> h >> n;

	vector<array<int, 2>> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i][0] >> A[i][1];
	}

	int na; cin >> na;
	vector<int> Pa(na);
	for (int& i : Pa) cin >> i;

	int nb; cin >> nb;
	vector<int> Pb(nb);
	for (int& i : Pb) cin >> i;

	map<array<int, 2>, int> M;
	for (int i = 0; i < n; i++) {
		int a = upper_bound(all(Pa), A[i][0]) - Pa.begin() - 1;
		int b = upper_bound(all(Pb), A[i][1]) - Pb.begin() - 1;
		M[{a, b}]++;
	}

	int mn = INT_MAX, mx = INT_MIN;
	for (auto [a, b] : M) {
		mn = min(mn, b);	
		mx = max(mx, b);
	}
	if (M.size() != (na + 1) * (nb + 1)) mn = 0;
	cout << mn << ' ' << mx << endl;

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

