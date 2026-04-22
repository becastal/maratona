#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, l; cin >> n >> l;

	vector<int> A(n * 24 + 1, 0);

	int p = 0;
	for (int i = 0, x; i < n; i++) {
		cin >> x;

		for (int j = 0; j <= 24; j++) {
			int s = x;
			for (int k = 0, pos = p + x + j; k < 24 and pos >= 0; k++) {
				// printf("pos: %d\n", pos);
				s += A[pos--];
			}
			if (s > l) continue;

			for (int k = 0, pos = p + j; k < x; k++) {
				A[pos++] = 1;	
			}
			p += j + x;
			break;
		}
	}
	cout << p << endl;

	for (int i = (int)A.size() - 1; i >= 0; i--) if (A[i]) {
		return cout << i + 1 << endl, 0;
	}
	assert(0);

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

