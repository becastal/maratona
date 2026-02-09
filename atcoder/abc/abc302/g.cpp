#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<int> A(n), B(n), Co(4);
	vector<vector<int>> C(4, vector<int>(4, 0));

	for (int& i : A) {
		cin >> i;
		i--;
		Co[i]++;
	}

	for (int i = 0, j = 0; i < 4; i++) {
		for (int k = 0; k < Co[i]; k++) {
			B[j++] = i;
		}
	}

	for (int i = 0; i < n; i++) {
		C[A[i]][B[i]]++;
	}

	int res = INT_MIN;
	vector<int> P(4);
	iota(all(P), 0);
	do {
		int f = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 4; j++) {
				f += C[P[i]][P[j]];
			}
		}
		res = max(res, f);
	} while (next_permutation(all(P)));
	cout << res << endl;

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

