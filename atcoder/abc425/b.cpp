#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<int> A(n), vis(n+1, 0);
	for (int& i : A) cin >> i;

	for (int i : A) if (i != -1) {
		if (vis[i]) return cout << "No" << endl, 0;
		vis[i] = 1;
	}

	cout << "Yes" << endl;
	for (int i = 0, p = 1; i < n; i++) if (A[i] == -1) {
		while (vis[p]) p++;
		A[i] = p++;	
	}
	for (int i : A) cout << i << ' '; cout << endl;

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

