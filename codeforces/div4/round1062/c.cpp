#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n), C(2, 0);
	
	for (int& i : A) {
		cin >> i;
		C[i & 1] = 1;
	}

	if (C[0] and C[1]) {
		sort(all(A));
	}
	for (int i : A) {
		cout << i << ' ';
	}
	cout << endl;

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

