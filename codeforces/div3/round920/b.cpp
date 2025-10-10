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
	string A, B; cin >> A >> B;
	
	int c10 = 0, c01 = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] == '1' and B[i] == '0') c10++;	
		if (A[i] == '0' and B[i] == '1') c01++;	
	}

	int x = min(c10, c01);
	cout << x + (c10 + c01 - 2 * x) << endl;

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
