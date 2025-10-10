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

	int n, q, cont = 0;
	while (cin >> n >> q and n) {
		cout << "CASE# " << ++cont << ':' << endl;
		
		vector<pair<int, int>> v;
        for (int i = 0, x; i < n; i++) {
            cin >> x; v.emplace_back(x, i + 1);
        }
        sort(v.begin(), v.end());

        while (q--) {
            int x; cin >> x;
            pair<int, int> a = {x, -INF};

            auto it = lower_bound(v.begin(), v.end(), a);
            if (it == v.end() or it->f != x) cout << x << " not found" << endl;
            else cout << x << " found at " << it - v.begin() + 1 << endl;
        }
	}
    
    return(0);
}
