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
	map<int, int> A;
	for (int i = 0, x; i < n; i++) {
		cin >> x; A[x]++;
	}

	for (int i = 0, x; i < m; i++) {
		cin >> x; A[x]--;
	}

	for (auto [a, b] : A) {
		for (int i = 0; i < b; i++) {
			cout << a << ' ';
		}
	}
	cout << endl;

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
