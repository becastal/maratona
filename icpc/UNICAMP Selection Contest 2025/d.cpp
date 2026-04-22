#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, l, soma = 0; cin >> n >> l;

	set<array<int, 2>> S;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		S.insert({x, i});
		soma += x;
	}
	if (soma < -l or soma >= l) return cout << "N" << endl, 0;

	int p = 0;
	vector<int> Res(n);
	for (int i = 0, s = 0; i < n; i++) {
		if (s < 0) {
			if ((*S.rbegin())[0] < 0) break;
			Res[p++] = (*S.rbegin())[0];
			s += (*S.rbegin())[0];
			S.erase(*S.rbegin());
		} else {
			if ((*S.begin())[0] > 0) break;
			Res[p++] = (*S.begin())[0];
			s += (*S.begin())[0];
			S.erase(*S.begin());
		}
	}

	while (S.size()) {
		Res[p++] = (*S.begin())[0];
		S.erase(*S.begin());
	}

	cout << "S" << endl;
	for (int i = 0; i < n; i++) {
		cout << Res[i] << " \n"[i == n-1];
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

