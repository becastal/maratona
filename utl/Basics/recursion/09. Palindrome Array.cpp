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

	function<bool(int, int)> f = [&] (int l, int r) {
		if (l > r or r < 0 or l > n) return true;
		if (v[l] != v[r]) return false;

		return true and f(l + 1, r - 1);
	};
 
	cout << (f(0, n - 1) ? "YES" : "NO") << endl;
    
    return(0);
}
