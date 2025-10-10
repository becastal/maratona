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

	vector<int> S;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		A[i] = -A[i];

		auto it = lower_bound(all(S), A[i]);	
		if (it == S.end()) S.push_back(A[i]);
		else *it = A[i];
	}
	int m = S.size();

	if (m == 1) return cout << 0 << endl, 0;
	if (m == 2) return cout << 1 << endl, 0;
	// pegar casos em que eh 2


	cout << 3 << endl, 0;

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

