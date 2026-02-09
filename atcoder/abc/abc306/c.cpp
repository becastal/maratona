#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> F(n, -1);
	for (int i = 0, x; i < 3 * n; i++) {
		cin >> x; x--;
		if (F[x] == -1) F[x] = 0;
		else if (!F[x]) F[x] = i;
	}

	vector<int> A(n);
	iota(all(A), 0);
	sort(all(A), [&](int a, int b) {
		return F[a] < F[b];
	});
	for (int i = 0; i < n; i++) {
		cout << A[i] + 1 << " \n"[i==n-1];
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

