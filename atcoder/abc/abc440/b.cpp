#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<int> T(n), P(n);
	for (int& i : T) {
		cin >> i;
	}

	iota(all(P), 0);
	sort(all(P), [&](int a, int b) {
		return T[a] < T[b];
	});

	cout << P[0] + 1 << ' ' << P[1] + 1 << ' ' << P[2] + 1 << endl;


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

