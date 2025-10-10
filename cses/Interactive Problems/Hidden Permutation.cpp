#include <bits/stdc++.h>
#define f first
#define s second
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	auto query = [](int i, int j) {
		cout << "? " << i+1 << ' ' << j+1 << endl;
		string x; cin >> x; return x == "YES";
	};

	int n; cin >> n;
	function<vector<int>(int, int)> f = [&](int l, int r) -> vector<int> {
		if (l == r) return { l };

		int m = l + r >> 1;
		vector<int> A = f(l, m), B = f(m+1, r);
		
		vector<int> C;
		int l_, r_;
		for (l_ = 0, r_ = 0; l_ < (int)A.size() and r_ < (int)B.size(); ) {
			if (query(A[l_], B[r_])) {
				C.push_back(A[l_++]);
			} else {
				C.push_back(B[r_++]);	
			}
		};
		while (l_ < (int)A.size()) C.push_back(A[l_++]);
		while (r_ < (int)B.size()) C.push_back(B[r_++]);

		return C;
	};
	vector<int> R = f(0, n-1);

	vector<int> res(n);
	for (int i = 0; i < n; i++) {
		res[R[i]] = i + 1;
	}

	cout << "! ";
	for (int i = 0; i < n; i++) {
		cout << res[i];
		if (i == n-1) cout << endl;
		else cout << ' ';
	}

	return(0);
}

int main()
{
    //_;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
