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
	for (int& vi : v)
		cin >> vi;

	function<bool(int, int)> f = [&] (int i, int j) {
		if (j < 0) j = 360 + j;
		else j %= 360;

		if (i == n) return !j;

		return f(i + 1, j + v[i]) or f(i + 1, j - v[i]);
	};

	cout << (f(0, 0) ? "YES" : "NO") << endl;
    
    return(0);
}
