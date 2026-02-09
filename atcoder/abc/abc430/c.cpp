#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, a, b; cin >> n >> a >> b;
	string S; cin >> S;

	vector<int> A(n + 1, 0), B(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		A[i] = A[i-1] + (S[i-1] == 'a');
		B[i] = B[i-1] + (S[i-1] == 'b');
	}

	ll res = 0;
	for (int l = 1, ra = 1, rb = 0; l <= n; l++) {
		ra = max(ra, l);	
		while (ra <= n and A[ra] - A[l-1] < a) ra++;
		while (rb + 1 <= n and B[rb + 1] - B[l-1] < b) rb++;

		int lo = max(ra, l);
		if (lo <= rb) res += (rb - lo + 1);
	}
	cout << res << endl;

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

