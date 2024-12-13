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

	int n = 8;
	vector<string> m(n);
	for (auto& i : m) cin >> i;

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int ok = 1;
			
			int ii = i;
			while (ii >= 0) {
				ok &= m[ii][j] != '#';
				ii--;
			}

			ii = i;
			while (ii < n) {
				ok &= m[ii][j] != '#';
				ii++;
			}

			int jj = j;
			while (jj >= 0) {
				ok &= m[i][jj] != '#';
				jj--;
			}

			jj = j;
			while (jj < n) {
				ok &= m[i][jj] != '#';
				jj++;
			}

			res += ok;
		}
	}

	cout << res << endl;
    
    return(0);
}
