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

	int n; cin >> n;
	vector<int> a(n), mx(n, 0), acum(n, 0);
	for (int& i : a) cin >> i, i--;

	for (int i = 0, wi; i < n; i++) {
		cin >> wi;
		acum[a[i]] += wi;
		mx[a[i]] = max(mx[a[i]], wi);
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		res += acum[i] - mx[i];
	}
	cout << res << endl;
    
    return(0);
}
