#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<int> A(n), R(n);

	ll s = 0;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		R[i] = max(0, A[i]);
		if (i) s += R[i] - R[i-1];
	}

	if (s > 0 and A[0] == -1) {
		R[0] = s;
		s = 0;
	}
	if (s < 0 and A[n-1] == -1) {
		R[n-1] = -s;
		s = 0;
	}

	s = abs(s);
	cout << s << endl;
	for (int i = 0; i < n; i++) {
		cout << R[i] << " \n"[i==n-1];
	}

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

