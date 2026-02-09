#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<array<int, 2>> A(n,  {-1, -1});

	for (int i = 0, fi, si; i < n; i++) {
		cin >> fi >> si; fi--;
		if (A[fi][0] < si) {
			swap(A[fi][0], A[fi][1]);
			A[fi][0] = si;
		} else if (A[fi][1] < si) {
			A[fi][1] = si;
		}
	}

	int res = 0, a = -1, b = -1;
	for (int i = 0; i < n; i++) {
		if (A[i][0] != -1 and A[i][1] != -1) {
			res = max(res, A[i][0] + A[i][1] / 2);
		}
		if (a < A[i][0]) {
			swap(a, b);
			a = A[i][0];
		} else if (b < A[i][0]) {
			b = A[i][0];
		}
	}
	cout << max(res, a + b) << endl;

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

