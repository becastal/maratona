#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, k; cin >> n >> k;
	vector<int> A(n), B(n);

	ll agr = 0;
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i];
		agr += B[i];
	}
	
	vector<int> P(n);
	iota(all(P), 0);
	sort(all(P), [&](int i, int j) { return A[i] < A[j]; });

	if (agr <= k) return cout << 1 << endl, 0;
	for (int l = 0, r; l < n; l = r) {
		r = l + 1;	
		ll rem = B[P[l]];
		while (r < n and A[P[l]] == A[P[r]]) {
			rem += B[P[r++]];
		}
		agr -= rem;
		if (agr <= k) return cout << A[P[l]] + 1 << endl, 0;
	}
	cout << *max_element(all(A)) + 1 << endl;

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

