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
		map<int, int> f;
		for (int& i : v) cin >> i, f[i]++;

		int pos = -1, res = INF;
		for (int i = 0; i < n; i++) {
			if (f[v[i]] == 1 and v[i] < res) {
				res = v[i];
				pos = i+1;
			}
		}
		cout << pos << endl;
	}
    
    return(0);
}
