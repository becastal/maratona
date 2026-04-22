#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<pair<int, int>> A(n);
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		A[i] = pair<int, int>(1 + (x < 0), abs(x));
	}

	vector<int> tenho(n+1, 0);
	for (int l = 0, r = 0; l < n; l++) {
		if (l) {
			auto [tp, a] = A[l-1];
			if (tp == 2) tenho[a]++;
		}

		while (r < n) {
			auto [tp, a] = A[r];

			if (tp == 2) tenho[a]--;
			else if (!tenho[a] <= 0) break;
			r++;
		}
	
		cout << (r - l) << " \n"[l==n-1];
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
