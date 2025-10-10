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

	int n, q; cin >> n >> q;
	vector<int> pos(n+1), quantos(n+1, 1);
	iota(pos.begin(), pos.end(), 0);

	int res = 0;
	while (q--) {
		int qi; cin >> qi;

		if (qi == 1) {
			int p, h; cin >> p >> h;

			if (quantos[pos[p]]-- == 2) {
				res--;
			};
			pos[p] = h;
			if (quantos[pos[p]]++ == 1) {
				res++;
			};
		} else {
			cout << res << endl;
		}
	}
    
    return(0);
}
