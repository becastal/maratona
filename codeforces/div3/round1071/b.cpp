#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	int s = 0;
	for (int i = 1; i < n; i++) {
		s += abs(A[i] - A[i-1]);
	}

	int res = s;
	for (int i = 1; i < n-1; i++) {
		res = min(res, s - abs(A[i] - A[i-1]) - abs(A[i] - A[i+1]) + abs(A[i+1] - A[i-1]));
	}
	res = min(res, s - abs(A[1] - A[0]));
	res = min(res, s - abs(A[n-1] - A[n-2]));
	cout << res << endl;

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

