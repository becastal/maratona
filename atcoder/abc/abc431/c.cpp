#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m, k; cin >> n >> m >> k;

	vector<int> A(n), B(m);
	for (int& i : A) cin >> i;
	for (int& i : B) cin >> i;

	sort(all(A));
	sort(all(B));

	for (int i = 0; i < k; i++) {
		if (A[i] > B[m - k + i]) return cout << "No" << endl, 0;
	}
	cout << "Yes" << endl;

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

