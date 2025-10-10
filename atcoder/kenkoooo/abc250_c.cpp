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
	vector<int> v(n), pos(n+1, 0);

	iota(v.begin(), v.end(), 1);
	iota(pos.begin(), pos.end(), -1);

	while (q--) {
		int xi; cin >> xi;	

		int prox = (pos[xi] == n-1 ? n-2 : pos[xi]+1);
		int v_prox = v[prox];

		swap(v[pos[xi]], v[prox]);
		swap(pos[xi], pos[v_prox]);

	}

	for (int i : v) cout << i << ' '; cout << endl;
    
    return(0);
}
