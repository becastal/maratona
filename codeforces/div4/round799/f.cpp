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

void solve() {
	int n; cin >> n;
	map<int, int> f;
	vector<int> v(n);
	for (int& i : v) cin >> i, i %= 10, f[i]++;
	
	int ok = 0;
	for (int i = 0; i <= 9 and !ok; i++) {
		for (int j = 0; j <= 9 and !ok; j++) {
			for (int k = 0; k <= 9 and !ok; k++) {
				if ((i + j + k) % 10 != 3) continue;

				if (f[i] > 0) {
					f[i]--;
					if (f[j] > 0) {
						f[j]--;
						if (f[k] > 0) {
							ok = 1;
						}
						f[j]++;
					}
					f[i]++;
				}
			}
		}
	}

	cout << (ok ? "YES" : "NO") << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
