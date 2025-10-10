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

void solve() {
	int n, x, y; cin >> n >> x >> y; x--, y--;
	vector<int> res(n, -1);

	int lado_a = y - x - 1;
	int lado_b = n - (lado_a + 2); 	

    if (lado_a & 1) {
        res[(x + 1) % n] = 2;
    }

    if (lado_b & 1) {
        res[(((x - 1) % n) + n) % n] = 2;
    }

	res[x] = 0;
	res[y] = 1;

	int agr = 0;
    int r = (y + 1) % n;
    while (res[r] == -1) {
        res[r] = agr;
        agr ^= 1;
        r = (r + 1) % n;
    }

    agr = 0;
    int l = (((y - 1) % n) + n) % n;
    while (res[l] == -1) {
        res[l] = agr;
        agr ^= 1;
        l = (((l - 1) % n) + n) % n;
    }

	for (int i : res) cout << i << ' '; cout << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
