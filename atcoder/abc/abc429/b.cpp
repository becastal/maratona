#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	int s = accumulate(all(A), 0);
	for (int i : A) {
		if (s - i == m) return cout << "Yes" << endl, 0;
	}
	cout << "No" << endl;

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

