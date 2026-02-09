#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n), B(n), P(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i];
		P[i] = i;
	}

	sort(all(P), [&](int i, int j) {
		__int128_t a = __int128_t(1) * A[i] * (A[j] + B[j]), b = __int128_t(1) * A[j] * (A[i] + B[i]);
		if (a == b) return i < j;
		return a > b;
	});

	for (int i = 0; i < n; i++) {
		cout << P[i] + 1 << " \n"[i==n-1];
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

