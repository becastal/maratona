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
	vector<int> P(n);
	for (int& i : P) {
		cin >> i;
	}

	int quero = n, l = 0, r = 0;
	while (l < n and P[l] == quero) {
		l++, quero--;
	}

	for (r = l; r < n and P[r] != quero; r++);

	for (int a = l, b = r; a < b; a++, b--) {
		swap(P[a], P[b]);
	}

	for (int i = 0; i < n; i++) {
		cout << P[i] << " \n"[i==n-1];
	}

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

