#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, x; cin >> n >> x;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	map<int, array<int, 2>> L;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (L.count(x - (A[i] + A[j]))) {
				auto [i_, j_] = L[x - (A[i] + A[j])];
				cout << i+1 << ' ' << j+1 << ' ' << i_+1 << ' ' << j_+1 << endl;
				return 0;
			}
		}

		for (int j = 0; j < i; j++) {
			L[A[i] + A[j]] = {i, j};
		}
	}
	cout << "IMPOSSIBLE" << endl;

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

