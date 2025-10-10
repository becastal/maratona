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
	vector<int> A(n), B(m);
	for (int& i : A) cin >> i;
	for (int& i : B) cin >> i;

	int b, g; cin >> b >> g;
	sort(A.begin(), A.end(), [&](int i, int j) {
		if (abs(i - g) == abs(j - g)) {
			return i < j;
		}
		return abs(i - g) < abs(j - g);
	});

	sort(B.begin(), B.end(), [&](int i, int j) {
		if (abs(i - g) == abs(j - g)) {
			return i < j;
		}
		return abs(i - g) < abs(j - g);
	});

	for (int i = 0; i < min(b, n); i++) {
		cout << A[i] << " \n"[i == min(b, n)-1];
	}
	for (int i = 0; i < min(b, m); i++) {
		cout << B[i] << " \n"[i == min(b, m)-1];
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
