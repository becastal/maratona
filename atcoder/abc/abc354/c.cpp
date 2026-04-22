#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n; cin >> n;
	vector<array<int, 3>> A(n);
	for (int i = 0; i < n; i++) {
		auto& [a, c, id] = A[i];
		cin >> a >> c; id = i;
	}

	vector<int> Res(n, 1);
	sort(rall(A));
	for (int i = 0, menor = LLONG_MAX; i < n; i++){ 
		auto& [a, c, id] = A[i];

		if (menor < c) {
			Res[id] = 0;
		} else menor = c;
	}

	cout << count(all(Res), 1) << endl;
	for (int i = 0; i < n; i++) if (Res[i]) { 
		cout << (i + 1) << " ";
	}
	cout << endl;

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

