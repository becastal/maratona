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

	int n, m, d, s = 0; cin >> n >> m >> d;
	vector<int> v(m), res(n);
	for (int& i : v) cin >> i, s += i;

	int ok = 0, agr = 0;
	for (int i = 0; i < m; i++) {
		if (agr + d + s > n + 1) {
			for (int j = agr + 1; j <= agr + v[i]; j++) {
				res[j-1] = i+1;	
			}
			agr = agr + 1 + v[i] - 1, s -= v[i];
		} else {
			for (int j = agr + d; j < agr + d + v[i]; j++) {
				res[j-1] = i+1;	
			}
			agr = agr + d + v[i] - 1, s -= v[i];
		}
	}

	if (agr + d >= n+1) {
		cout << "YES" << endl;
		for (int i : res) cout << i << ' '; cout << endl;
	} else cout << "NO" << endl;
    
    return(0);
}
