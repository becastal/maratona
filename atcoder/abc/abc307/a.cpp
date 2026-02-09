#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> R(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0, x; j < 7; j++) {
			cin >> x;
			R[i] += x;
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << R[i] << " \n"[i==n-1];
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

