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

	int n, W; cin >> n >> W;
	vector<int> w(n), v(n);
	for (int i = 0; i < n; i++)
		cin >> w[i] >> v[i];
	
	function<int(int, int)> f = [&] (int i, int p) {
		if (p < 0) return -INF;
		if (i == n) return 0;
		
		return max(f(i + 1, p), f(i + 1, p - w[i]) + v[i]);
	};
 
 	cout << f(0, W) << endl;
    
    return(0);
}
