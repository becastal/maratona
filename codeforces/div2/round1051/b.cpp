#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, k; cin >> n >> k;

	vector<int> A(n), B(k);
	for (int& i : A) cin >> i;
	for (int& i : B) cin >> i;

	sort(rall(A));
	sort(all(B));

	ll res = 0;
	int j = 0;
	for (int i = 0; i < k; i++) {
		for (int ii = 0; ii < B[i] - 1 and j < n; ii++) {
			res += A[j++];
		}
		j++;
	}

	while (j < n) res += A[j++];
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

