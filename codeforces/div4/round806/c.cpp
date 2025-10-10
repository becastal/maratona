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

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> v(n);
		for (int& i : v) cin >> i;

		for (int i = 0; i < n; i++) {
			int m; cin >> m;
			for (int j = 0; j < m; j++) {
				char c; cin >> c;
				if (c == 'D') {
					v[i] = (v[i] + 1) % 10;
				} else {
					v[i] = (v[i] - 1 + 10) % 10;
				}
			}
		}

		for (int i : v) cout << i << ' '; cout << endl;
	}
    
    return(0);
}
