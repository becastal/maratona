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
	int n, m; cin >> n >> m;

	vector<int> A(m);
	for (int& i : A) cin >> i;
	sort(all(A));

	for (int i = 0, l = 0, r = m-1; i < n; i += 2, l++, r--) {
		for (int j = 0; j < 3; j++) {
			cout << A[l] << ' ' << A[r] << " \n"[j==2];
		} 
		if (i < n-1) {
			for (int j = 0; j < 3; j++) {
				cout << A[r] << ' ' << A[l] << " \n"[j==2];
			}
		}
	}

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
