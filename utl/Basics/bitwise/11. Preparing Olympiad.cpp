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
	int n, l, r, x;
	cin >> n >> l >> r >> x;
	vector<int> v(n);
	for (int& vi : v)
		cin >> vi;

	function<int(int, int, int, int)> f = [&] (int i, int j, int M, int m) {
		if (i == n and j >= l and j <= r and (M - m) >= x) return 1;
		else if (i == n) return 0;

		return f(i + 1, j + v[i], max(M, v[i]), min(m, v[i])) + f(i + 1, j, M, m);
	};

	cout << f(0, 0, -INF, INF) << endl;
    
    return(0);
}
