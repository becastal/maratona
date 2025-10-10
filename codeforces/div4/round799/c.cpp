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
		int n = 8;
		vector<string> v(n);
		for (auto& i : v) cin >> i;

		int ok = 0;
		for (int i = 1; i < n-1 and !ok; i++) {
			for (int j = 1; j < n-1 and !ok; j++) {
				if (v[i][j] == '#' and
					v[i+1][j+1] == '#' and
					v[i-1][j-1] == '#' and 
					v[i+1][j-1] == '#' and 
					v[i-1][j+1] == '#') {
					ok = 1;
					cout << i+1 << ' ' << j+1 << endl;
				}
			}
		}
	}
    
    return(0);
}
