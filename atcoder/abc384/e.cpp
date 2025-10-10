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
typedef pair<int, int> ii;

vector<ii> movs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main()
{
    _;

    int n, m; cin >> n >> m;
    ll X; cin >> X;
    ii eu; cin >> eu.f >> eu.s; eu.f--, eu.s--;

    vector<vector<ll>> M(n, vector<ll>(m));
    for (auto& l : M) for (auto& c : l) cin >> c;
    ll res = 0;

    priority_queue<pair<ll, ii>> naodeu;
    auto dentro = [&](ii a) {
        return a.f >= 0 and a.f < n and a.s >= 0 and a.s < m;
    };

    auto valido = [&](ii a) {
        return dentro(a) and M[a.f][a.s] != -1 and !(M[a.f][a.s] >= (res + X - 1) / X);
    };

    auto vai = [&](auto& vai, ii a) -> void {
        res += M[a.f][a.s];
        M[a.f][a.s] = -1;

        vector<pair<ll, ii>> poss;
        for (auto mov : movs) {
            ii v; v.f = a.f + mov.f; v.s = a.s + mov.s;

            if (dentro(v)) {
                poss.emplace_back(M[v.f][v.s], v);
            }
        }
        sort(poss.begin(), poss.end());

        for (auto [valv, v] : poss) {
            if (valido(v)) {
                vai(vai, v);
            } else {
                naodeu.emplace(valv, v);
            }
        }

        while (!naodeu.empty() and (M[naodeu.top().s.f][naodeu.top().s.s] == -1 or valido(naodeu.top().s))) {
            ii top_pos = naodeu.top().s;
            res += max(0LL, M[top_pos.f][top_pos.s]);
            M[top_pos.f][top_pos.s] = -1;
            naodeu.pop();
        }
    };
    vai(vai, eu);

    cout << res << endl;

    return 0;
}

