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

	int ok = 1;
	for (int i = 0; i < n and ok; i++) {
		for (int j = 0; j < m and ok; j++) if (A[i][j] == '#') {
			int cont = 0;

			if (i) cont += A[i-1][j] == '#';	
			if (j) cont += A[i][j-1] == '#';	
			if (i + 1 < n) cont += A[i+1][j] == '#';
			if (j + 1 < m) cont += A[i][j+1] == '#';

			ok &= (cont == 2) or (cont == 4);
		}
	}
	cout << (ok ? "Yes" : "No") << endl;

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

