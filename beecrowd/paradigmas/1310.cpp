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

	int n;
	while (cin >> n) {
		vector<int> v(n);
		int x; cin >> x;

		for (int& i : v) cin >> i, i -= x;

		int res = 0, agr = 0;
		for (int i : v) {
			agr = max(0, agr + i);
			res = max(res, agr);
		}

		cout << res << endl;
	}
    
    return(0);
}
