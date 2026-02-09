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

	vector<int> C(2, -1);
	for (int i = 0; i < n; i++) if (A[i] ^ B[i]) {
		C[i & 1] = i;
	}

	int c = count(all(A), 1) + count(all(B), 1);
	if (c & 1 ^ 1) return cout << "Tie" << endl, 0;
	cout << (C[0] < C[1] ? "Mai" : "Ajisai") << endl;

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

