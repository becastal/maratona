#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	vector<string> A(n);
	for (auto& i : A) cin >> i;

	vector<int> C(n, 0);
	for (int j = 0; j < m; j++) {
		int c0 = 0, c1 = 0;
		for (int i = 0; i < n; i++) {
			if (A[i][j] == '0') c0++;	
			else c1++;
		}
		if (!c0 or !c1) continue;

		char c = (c0 < c1 ? '0' : '1');
		for (int i = 0; i < n; i++) {
			if (A[i][j] == c) {
				C[i]++;
			}
		}
	}

	int r = *max_element(all(C));
	for (int i = 0; i < n; i++) {
		if (C[i] == r) {
			cout << (i + 1) << ' ';
		}
	}
	cout << endl;

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

