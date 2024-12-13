#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

signed main() {
    _;

    int n, m; 
    cin >> n >> m;
    vector<int> a(n), b(m);
	
    int eu = 0;
    for (int& i : a) cin >> i, eu ^= i;

    set<int> col;
    for (int& i : b) cin >> i, col.insert(i);

    auto da = [&] {
        int ok = 0, num = 0;
		
        for (int i = 0; i < 31 and !ok; i++) {
            num |= (1 << i);
            ok |= col.count(eu ^ num);
        }
        return ok or col.count(eu);
    };

    int res = da();
	int q; 
    cin >> q;
    while (q--) {
        char c; 
        int x;
        cin >> c >> x;

        eu ^= x;
		res += da();
    }

    cout << res << endl;

    return 0;
}

