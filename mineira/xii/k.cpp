#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<array<int, 2>> A(n);
	for (int i = 0, p, v; i < n; i++) {
		cin >> p >> v;
		int ti = (i + 1);
		A[i] = {p + (v * i), i};	
	}

	cout << A.size() << endl;
	for (auto [x, t] : A) {
		cout << x << ' ' << t << endl;
	}

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

