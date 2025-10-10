#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	for (int l = 1; l <= n-2; l++) {
		for (int r = l; r <= n-2; r++) {
			int a = 0, b = 0, c = 0;
			for (int i = 0; i < l; i++) a = (a + A[i]) % 3;
			for (int i = l; i <= r; i++) b = (b + A[i]) % 3;
			for (int i = r+1; i < n; i++) c = (c + A[i]) % 3;

			if ((a != b and a != c and c != b) or (a == b and b == c)) return cout << l << ' ' << r+1 << endl, 0;
		}
	}
	cout << 0 << ' ' << 0 << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

