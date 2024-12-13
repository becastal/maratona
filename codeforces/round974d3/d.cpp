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
    int n, d, k;
    cin >> n >> d >> k;

    vector<int> I(n+1, 0), F(n+1, 0);
    for (int i = 0, l, r; i < k; i++) {
        cin >> l >> r;
		I[l]++, F[r]++;
    }

	for (int i = 0; i < n; i++) {
		I[i+1] += I[i];
		F[i+1] += F[i];
	}

    int idx_irm = -1, soma_irm = -INF;
    int idx_mae = -1, soma_mae = INF;

    for (int i = d; i <= n; i++) {
        ll soma = I[i] - F[i-d];
        if (soma > soma_irm) {
            soma_irm = soma;
            idx_irm = i-d+1;
        }

        if (soma < soma_mae) {
            soma_mae = soma;
            idx_mae = i-d+1;
        }
    }

    cout << idx_irm << ' ' << idx_mae << endl;
}

int main() {
    _;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

