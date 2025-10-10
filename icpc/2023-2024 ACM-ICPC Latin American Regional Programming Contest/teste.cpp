#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
    na real cada (a, b, d) gera 4 segmentos de reta (as bordas do quadrado em (u,v)).
    representar cada segmento como um retângulo de espessura 1 (zero numa dimensão).
*/

// (u, v) = (x + y, x - y)
// (x, y) = ((u + v) / 2, (u - v) / 2)
struct rect {
    int x1, y1, x2, y2; // intervalos INCLUSIVOS

    int area() const {
        return max(0, x2 - x1) * max(0, y2 - y1); // não usamos, mas mantive
    }

    bool empty() const {
        return x2 < x1 || y2 < y1;
    }

    rect intersec(const rect& b) const {
        int nx1 = max(x1, b.x1);
        int ny1 = max(y1, b.y1);
        int nx2 = min(x2, b.x2);
        int ny2 = min(y2, b.y2);
        if (nx2 < nx1 || ny2 < ny1) return {1, 1, 0, 0}; // vazio
        return { nx1, ny1, nx2, ny2 };
    }
};

pair<int,int> rot(int x, int y) { return {x + y, x - y}; }
pair<int,int> rot_(int u, int v) { return { (u + v) / 2, (u - v) / 2 }; }

/*
    para (a,b,d), em (u,v) fica um quadrado centrado em (u0,v0) de lado 2d.
    as 4 bordas são:
      v = v0 + d, u ∈ [u0 - d, u0 + d]
      v = v0 - d, u ∈ [u0 - d, u0 + d]
      u = u0 + d, v ∈ [v0 - d, v0 + d]
      u = u0 - d, v ∈ [v0 - d, v0 + d]
    cada uma vira um rect com espessura 0 numa dimensão.
*/
vector<rect> interpret_border(int a, int b, int d) {
    auto [u0, v0] = rot(a, b);
    if (d == 0) {
        // ponto único
        return { rect{u0, v0, u0, v0} };
    }
    vector<rect> R;
    // horizontais (v fixo)
    R.push_back(rect{u0 - d, v0 + d, u0 + d, v0 + d});
    R.push_back(rect{u0 - d, v0 - d, u0 + d, v0 - d});
    // verticais (u fixo)
    R.push_back(rect{u0 + d, v0 - d, u0 + d, v0 + d});
    R.push_back(rect{u0 - d, v0 - d, u0 - d, v0 + d});
    return R;
}

vector<rect> intersect_sets(const vector<rect>& A, const vector<rect>& B) {
    vector<rect> C;
    C.reserve(A.size() * B.size());
    for (const auto& ra : A) {
        for (const auto& rb : B) {
            rect rc = ra.intersec(rb);
            if (!rc.empty()) C.push_back(rc);
        }
    }
    return C;
}

int solve() {
    int n; cin >> n;

    vector<array<int,3>> P(n);
    for (auto& [a,b,d] : P) cin >> a >> b >> d;

    // conjunto corrente de bordas como retângulos finos
    vector<rect> cur = interpret_border(P[0][0], P[0][1], P[0][2]);
    for (int i = 1; i < n; i++) {
        auto nxt = interpret_border(P[i][0], P[i][1], P[i][2]);
        cur = intersect_sets(cur, nxt);
        // opcional: reduzir tamanho removendo retângulos contidos (não estritamente necessário)
        if (cur.empty()) break;
    }

    // varrer os pontos de grade nos retângulos (bordas), respeitando paridade u ~ v
    vector<array<int,2>> R;
    for (const auto& r : cur) {
        if (r.empty()) continue;

        if (r.y1 == r.y2) {
            // horizontal: v fixo
            int v = r.y1;
            for (int u = r.x1; u <= r.x2; ++u) {
                if ( ((u ^ v) & 1) ) continue; // u e v precisam ter mesma paridade
                auto [x, y] = rot_(u, v);
                R.push_back({x, y});
            }
        } else if (r.x1 == r.x2) {
            // vertical: u fixo
            int u = r.x1;
            for (int v = r.y1; v <= r.y2; ++v) {
                if ( ((u ^ v) & 1) ) continue;
                auto [x, y] = rot_(u, v);
                R.push_back({x, y});
            }
        } else {
            // deve ser ponto (ou um retângulo 1x1 vindo de intersecção de horizontais/verticais adjacentes)
            for (int u = r.x1; u <= r.x2; ++u) {
                for (int v = r.y1; v <= r.y2; ++v) {
                    if ( ((u ^ v) & 1) ) continue;
                    auto [x, y] = rot_(u, v);
                    R.push_back({x, y});
                }
            }
        }
    }

    sort(all(R));
    R.erase(unique(all(R)), R.end());

    for (auto [a,b] : R) {
        cout << a << ' ' << b << endl;
    }
    return 0;
}

int main() {
    _;
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}
