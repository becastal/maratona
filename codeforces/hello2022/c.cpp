#include <bits/stdc++.h>
#define f first
#define s second
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int query(int x) {
	cout << "? " << x << endl;
	int res; cin >> res;
	return res;
}

void solve() {
	int n; cin >> n;

	vector<int> res(n, 0), m(n, 0);

	for (int i = 0; i < n; i++) {
		if (m[i] == 1) continue;

		int ult = query(i+1);
		while (1) {
			int x = query(i+1);
			res[ult-1] = x;
			if (ult == x) {
				m[x-1] = 1;
				break;
			}
			if (m[x-1] == 1) break;

			m[x-1] = 1;
			ult = x;
		}
	}

	cout << "! ";
	for (int i : res) cout << i << ' ';
	cout << endl;
}

int main()
{
    //_;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
