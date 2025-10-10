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

	int n, m; cin >> n >> m;
	vector<string> a(n), b(n);

	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;
    
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int ok = 1;
			for (int ii = 0; ii < n and ok; ii++) {
				for (int jj = 0; jj < m and ok; jj++) {
					ok &= a[(ii - i + n) % n][(jj - j + m) % m] == b[ii][jj];	
				}
			}
			res |= ok;
		}
	}
	cout << (res ? "Yes" : "No") << endl;

    return(0);
}
