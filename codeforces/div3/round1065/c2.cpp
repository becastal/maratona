#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n), B(n);

	for (int& i : A) cin >> i;
	for (int& i : B) cin >> i;

	for (int k = 25; k >= 0; k--) {

		int c = 0;
		vector<int> C(2, 0), P;
		for (int i = 0; i < n; i++) {
			int a = (A[i] >> k & 1), b = (B[i] >> k & 1);
			if (a ^ b) {
				C[i & 1] = i;
				P.push_back(i);
			}
			c += a + b;
		}
		if ((c & 1) ^ 1) continue;
		return cout << (C[0] < C[1] ? "Mai" : "Ajisai") << endl, 0;
	}
	cout << "Tie" << endl;

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

