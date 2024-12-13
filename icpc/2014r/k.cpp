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

	int c, n; cin >> c >> n;
	vector<int> v(c, 0);

	for (int i = 0, x; i < n; i++) {
		cin >> x; v[x] = 1;
	}

	for (int i = 1; i < c; i++) {
		v[i] += v[i-1];
	}

	bool tudo = 0;
	for (int i = 0; i < (c/n) and !tudo; i++) {
		bool fatia = 1;
		for (int j = 0; j < n-1 and fatia; j++) {
			fatia &= v[i + (j+1) * (c/n)-1] == v[i + j*(c/n)-1] + 1;
		}
		tudo |= fatia;
	}

	cout << (tudo ? 'S' : 'N') << endl;
    
    return(0);
}
