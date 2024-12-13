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

	// testar todas as ordens e, dentre todas as ordens, testar todas as reversoes.
	// tava no caminho certo, mas apanhando pra implementar.
	// o(n!2**n(n));

	int n; cin >> n;
	double s, t;
	cin >> s >> t;

    vector<array<int, 4>> v(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> v[i][j];
        }
    }

    auto dist = [] (array<int, 4>& p) {
		return sqrt((p[2] - p[0]) * (p[2] - p[0]) + (p[3] - p[1]) * (p[3] - p[1]));
	};

    auto reverso = [] (array<int, 4>& p) {
		array<int, 4> res = {p[2], p[3], p[0], p[1]};
        return res;
    };
    
    sort(v.begin(), v.end());
    double res = 1e15;
    do {
		for (int i = 0; i < (1 << n); i++) {
			double agr = 0;
			array<int, 4> ult {0, 0, 0, 0};

			for (int j = 0; j < n; j++) {
				array<int, 4> seg = (i & (1 << j) ? v[j] : reverso(v[j]));

				agr += dist(seg) / t;
				array<int, 4> amais = {ult[2], ult[3], seg[0], seg[1]};
				agr += dist(amais)/ s;			

				ult = seg;
			}
			res = min(res, agr);
		}
    } while (next_permutation(v.begin(), v.end()));

    cout << fixed << setprecision(12) << res << endl;

    return 0;
}


