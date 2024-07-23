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
	while (t--)
	{
		int a, b, c; cin >> a >> b >> c;
		int res = 0;

		function<void(int, int, int, int)> f = [&] (int i, int ai, int bi, int ci) {
			if (i > 5) return;
			res = max(res, ai * bi * ci);

			f(i + 1, ai + 1, bi, ci);
			f(i + 1, ai, bi + 1, ci);
			f(i + 1, ai, bi, ci + 1);
		};
		
		f(0, a, b, c);
		cout << res << endl;
	}
    
    return(0);
}
