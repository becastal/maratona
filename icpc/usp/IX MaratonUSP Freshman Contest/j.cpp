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

	int n, k; cin >> n >> k;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	map<int, int> f;
	int tam = 0, ri = -1, li = -1;
	for (int r = 0, l = 0; r < n; r++) {
		f[v[r]]++;

		while (f.size() > k) {
			if (--f[v[l]] == 0) f.erase(v[l]);
			l++;
		}
		
		if (r - l + 1 > tam) {
			tam = r - l + 1;
			li = l;
			ri = r;
		}
	}

	cout << tam << endl << li+1 << ' ' << ri+1 << endl;
    
    return(0);
}
