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

	vector<int> v(n+1, 0);

	for (int i = 0, x; i < k; i++) {
		cin >> x;
		for (int j = 1; j <= x; j++) {
			v[j]++;
		}
	}

	ll res = 0;
	for (int i = 1; i <= n; i++) {
		res += (1LL << (v[i]));
	}
	cout << res << endl;
    
    return(0);
}
