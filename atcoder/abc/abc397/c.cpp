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
	vector<int> v(n);
	map<int, int> fa, fb;

	for (int& i : v) cin >> i, fb[i]++;

	int res = -INF;
	for (int i = 0; i < n-1; i++) {
		fa[v[i]]++;
		if (--fb[v[i]] == 0) fb.erase(v[i]);
		res = max(res, (int)fa.size() + (int)fb.size());
	}
	cout << res << endl;
		
    return(0);
}
