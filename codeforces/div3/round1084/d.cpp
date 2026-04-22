#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, a, b; cin >> n >> a >> b; a--, b--;
	vector<int> A, B;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		if (i >= a and i < b) {
			B.push_back(x);
		} else {
			A.push_back(x);
		}
	}

	int p = min_element(A.begin(), A.end()) - A.begin();
	vector<int> B_(B);
	for (int i = a; i < b; i++) {
		int i_ = i + p;
		if (i_ >= (int)B.size()) {
			i_ -= (int)B.size();
		}
		B_[i] = B[i_];
	}

	auto it = A.begin();
	int m = B[p];
	while (it != A.end() and *it < m) {
		it = next(it);
	}
	A.insert(it, all(B_));

	for (int i = 0; i < n; i++) {
		cout << A[i] << " \n"[i==n-1];
	}

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

