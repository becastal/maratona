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

int f[(int)1e6+10];
int solve() {
	int n, k; cin >> n >> k;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	int res = -1, l_, r_;
	for (int r = 0, l = 0, cont; r < n; r++) {
		if (++f[A[r]] == 1) {
			cont++;
		}

		while (cont > k) {
			if (--f[A[l++]] == 0) {
				cont--;
			}
		}

		if (r - l + 1 > res) {
			res = r - l + 1;
			r_ = r + 1;
			l_ = l + 1;
		}
	}

	cout << l_ << ' ' << r_ << endl;

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
