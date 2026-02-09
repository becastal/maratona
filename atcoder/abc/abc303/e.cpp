#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<int> E(n, 0);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		E[u]++, E[v]++;
	}

	vector<int> R;
	int agr = n;
	for (int i = 0; i < n; i++) {
		if (E[i] > 2) {
			agr -= E[i] + 1;
			R.push_back(E[i]);
		}
	}

	for (int i = 0; i < agr / 3; i++) {
		R.push_back(2);
	}

	sort(all(R));
	for (int i = 0; i < (int)R.size(); i++) {
		cout << R[i] << " \n"[i==(int)R.size()-1];
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

