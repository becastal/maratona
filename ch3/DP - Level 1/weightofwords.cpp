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

	int l, w; cin >> l >> w;

	if (w < l or w > 26 * l) return cout << "impossible" << endl, 0;

	int agr = 26 * l;
	string res = string(l, 'z');

	for (int i = 0; i < l and agr > w; i++) {
		int dist = min(agr - w, 25);
		agr -= dist;
		res[i] = res[i] - dist;
	}

	cout << res << endl;
    
    return(0);
}
