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

const int maxn = 3e5+10;
vector<int> divi[maxn];

void crivo(int lim) {
    for (int i = 1; i <= lim; i++) {
        for (int j = i; j <= lim; j += i) {
            divi[j].push_back(i);
        }
    }
}

void solve() {
	int n, m, q; cin >> n >> m >> q;
	vector<int> a(n), b(m);
	ll sa = 0, sb = 0;

	for (int& i : a) cin >> i, sa += i;
	for (int& i : b) cin >> i, sb += i;
	unordered_set<ll> posso_a, posso_b;

	for (int i : a) posso_a.insert(sa - i);
	for (int i : b) posso_b.insert(sb - i);

	while (q--) {
		int x, ok = 0; cin >> x;

		for (int i : divi[abs(x)]) {
			if ((posso_a.count(i) and posso_b.count(x/i)) or (posso_a.count(x/i) and posso_b.count(i)) or
				(posso_a.count(-i) and posso_b.count(-x/i)) or (posso_a.count(-x/i) and posso_b.count(-i))
				) {
				ok = 1;
				break;
			}
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}

int main()
{
    _;

	crivo(maxn-1);
	solve();
    
    return(0);
}
