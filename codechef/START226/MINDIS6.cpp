#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, k; cin >> n >> k;

	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	map<int, int> M;
	for (int i = 0; i < n; i++) if (A[i] != A[0]) {
		M[A[i]]++;
	}
	int m = (int)M.size() + 1;

	vector<int> B;
	for (auto [a, b] : M) { 
		B.push_back(b);
	}

	sort(all(B));
	for (int i = 0; i < m - 1; i++) {
		k -= B[i];
		if (k < 0) return cout << m - i << endl, 0;
	}
	cout << 1 << endl;

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

