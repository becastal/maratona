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
		vector<string> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		for (int i = n-1; i >= 0; i--) {
			for (int j = 0; j < 4; j++) {
				if (v[i][j] == '#') {
					cout << j+1 << ' ';
				}
			}
		}
		cout << endl;
	}
    
    return(0);
}
