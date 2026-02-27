#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, k, mx = 0, res = 0; cin >> n >> k;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
		mx = max(mx, i);
	}
	
	vector<int> T(n);
	for (int i = 0, agr = 0; i < n; i++) {
		agr = max(agr, A[i]);
		T[i] = max(T[i], agr);
		agr -= k;
	}


	for (int i = n-1, agr = 0; i >= 0; i--) {
		agr = max(agr, A[i]);
		T[i] = max(T[i], agr);
		agr -= k;
	}

	for (int i = 0; i < n; i++) {
		res += max(0LL, T[i] - A[i]);
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

