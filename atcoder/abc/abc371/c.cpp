#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = LLONG_MAX;
using namespace std;
typedef pair<int, int> ii;

int main()
{
    _;

    // testar todas as combinacoes de ed e ver a mais barata pra deixar ambos iguais.
    int n; cin >> n;
    set<ii> a, b;

    int ma; cin >> ma;
    for (int i = 0, u, v; i < ma; i++) {
        cin >> u >> v; u--, v--;
		a.emplace(u, v);
		a.emplace(v, u);
    }
    int mb; cin >> mb;
    for (int i = 0, u, v; i < mb; i++) {
        cin >> u >> v; u--, v--;
		b.emplace(u, v);
		b.emplace(v, u);
    }

	vector p(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			cin >> p[i][j];
			p[j][i] = p[i][j];
		}
	}

	vector<int> perm(n);
	iota(perm.begin(), perm.end(), 0);

	int res = INF;
	do {
		int agr = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				agr += p[i][j] * (a.count(ii(perm[i], perm[j])) != b.count(ii(i, j)));
			}
		}
		res = min(res, agr);
	} while (next_permutation(perm.begin(), perm.end()));

    cout << res << endl;
    
    return 0;
}

