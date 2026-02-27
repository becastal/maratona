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
	for (int i = 0; i < k; i++) {
		M[A[i]]++;
	}

	auto calc = [&]() {
		return M.rbegin()->first - M.begin()->first;
	};

	int res = calc();
	for (int i = k; i < n; i++) {
		if (--M[A[i-k]] == 0) M.erase(A[i-k]);	
		M[A[i]]++;
		res = max(res, calc());
	}
	cout << res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

