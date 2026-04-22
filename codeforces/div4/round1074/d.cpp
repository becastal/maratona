#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m, h; cin >> n >> m >> h;

	vector<int> A(n), B(n), Alt;
	for (int& i : A) {
		cin >> i;
	}
	B = A;

	for (int i = 0, b, c; i < m; i++) {
		cin >> b >> c; b--;
		B[b] += c;
		Alt.push_back(b);
		if (B[b] > h) {
			for (int p : Alt) {
				B[p] = A[p];
			}
			Alt.clear();
		}
	}

	for (int i = 0; i < n; i++) {
		cout << B[i] << " \n"[i==n-1];
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

