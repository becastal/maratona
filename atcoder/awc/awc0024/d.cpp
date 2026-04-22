#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, w, k; cin >> n >> w >> k;

	vector<int> Res(n + 1);
	for (int i = 0, l; i < k; i++) {
		cin >> l; l--;
		Res[l]++;
		Res[l + w]--;
	}

	for (int i = 0; i < n; i++) {
		if (i) Res[i] += Res[i-1];
		cout << Res[i] << " \n"[i==n-1];
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

