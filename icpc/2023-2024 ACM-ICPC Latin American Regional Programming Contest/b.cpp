#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	map<int, int> F;
	
	for (int i = 0, x; i < 3 * n; i++) {
		cin >> x;
		F[x]++;
	}

	vector<int> C(3, 0);
	for (auto [a, b] : F) {
		C[b % 3]++;
	}

	if (!C[1] and !C[2]) return cout << "N" << endl, 0;
	cout << "Y" << endl;

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

