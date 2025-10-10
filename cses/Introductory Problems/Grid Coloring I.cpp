#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	vector<string> A(n);
	for (auto& i : A) cin >> i;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			set<char> ok = {'A', 'B', 'C', 'D'};
			ok.erase(A[i][j]);
			if (i) ok.erase(A[i-1][j]);
			if (j) ok.erase(A[i][j-1]);
			A[i][j] = *ok.begin();
		}
	}

	for (auto i : A) cout << i << endl;

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
