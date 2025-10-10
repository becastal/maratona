#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
    cada (a,b,d) gera 4 bordas do quadrado em (u,v).
    guardamos só essas bordas como “retângulos” de espessura 0 (horizontais/verticais).
    após cada interseção, mesclamos por borda => no máx 4 segmentos.
*/

// (u, v) = (x + y, x - y)
// (x, y) = ((u + v) / 2, (u - v) / 2)
struct rect {
    int x1, y1, x2, y2; // inclusivo
    bool empty() const { return x2 < x1 || y2 < y1; }
    rect intersec(const rect& b) const {
        int nx1 = max(x1, b.x1), ny1 = max(y1, b.y1);
        int nx2 = min(x2, b.x2), ny2 = min(y2, b.y2);
        if (nx2 < nx1 || ny2 < ny1) return {1,1,0,0};
        return {nx1, ny1, nx2, ny2};
    }
};

pair<int,int> rot(int x, int y) { return {x + y, x - y}; }
pair<int,int> rot_(int u, int v) { return {(u + v) / 2, (u - v) / 2}; }

// gera as 4 bordas (ou ponto) do quadrado do (a,b,d) em coordenadas (u,v)
static inline vector<rect> make_edges(int a, int b, int d){
    auto [u0,v0] = rot(a,b);
    if (d == 0) return { {u0, v0, u0, v0} };
    vector<rect> B;
    B.reserve(4);
    // horizontais (v fixo)
    B.push_back({u0 - d, v0 + d, u0 + d, v0 + d});
    B.push_back({u0 - d, v0 - d, u0 + d, v0 - d});
    // verticais (u fixo)
    B.push_back({u0 + d, v0 - d, u0 + d, v0 + d});
    B.push_back({u0 - d, v0 - d, u0 - d, v0 + d});
    return B;
}

// mescla uma lista de interseções que estão TODAS na mesma borda horizontal (mesmo y)
static inline void merge_h(const vector<rect>& tmp, int y, vector<rect>& out){
    if (tmp.empty()) return;
    vector<pair<int,int>> segs; segs.reserve(tmp.size());
    for (auto &r: tmp) segs.emplace_back(r.x1, r.x2);
    sort(all(segs));
    int L = segs[0].first, R = segs[0].second;
    for (size_t i = 1; i < segs.size(); ++i){
        if (segs[i].first <= R + 1) R = max(R, segs[i].second); // junta adjacentes
        else { out.push_back({L, y, R, y}); L = segs[i].first; R = segs[i].second; }
    }
    out.push_back({L, y, R, y});
}

// mescla uma lista de interseções que estão TODAS na mesma borda vertical (mesmo u)
static inline void merge_v(const vector<rect>& tmp, int x, vector<rect>& out){
    if (tmp.empty()) return;
    vector<pair<int,int>> segs; segs.reserve(tmp.size());
    for (auto &r: tmp) segs.emplace_back(r.y1, r.y2);
    sort(all(segs));
    int L = segs[0].first, R = segs[0].second;
    for (size_t i = 1; i < segs.size(); ++i){
        if (segs[i].first <= R + 1) R = max(R, segs[i].second);
        else { out.push_back({x, L, x, R}); L = segs[i].first; R = segs[i].second; }
    }
    out.push_back({x, L, x, R});
}

// conv comprimido: intersecta A com as 4 bordas de B e já mescla por borda
static inline vector<rect> conv_compress(const vector<rect>& A, const vector<rect>& B){
    vector<rect> C; C.reserve(8); // no máx poucas peças
    for (const auto& b : B){
        vector<rect> tmp; tmp.reserve(A.size());
        for (const auto& a : A){
            rect c = a.intersec(b);
            if (!c.empty()) tmp.push_back(c);
        }
        if (tmp.empty()) continue;
        if (b.y1 == b.y2) merge_h(tmp, b.y1, C);    // horizontal
        else              merge_v(tmp, b.x1, C);    // vertical
    }
    return C;
}

int solve() {
    int n; cin >> n;

    vector<rect> A; A.reserve(8);
    for (int i = 0; i < n; ++i){
        int a,b,d; cin >> a >> b >> d;
        vector<rect> B = make_edges(a,b,d);
        if (i == 0) {
            // primeiro: já comprime em si (junta bordas idênticas, se houver)
            vector<rect> init;
            // horizontais
            vector<rect> H; H.reserve(2);
            H.push_back(B[0]); H.push_back(B[1]);
            merge_h(H, B[0].y1, init); // v0+d
            merge_h({B[1]}, B[1].y1, init); // v0-d (já isolada)
            // verticais
            vector<rect> V; V.reserve(2);
            V.push_back(B[2]); V.push_back(B[3]);
            merge_v(V, B[2].x1, init); // u0+d
            merge_v({B[3]}, B[3].x1, init); // u0-d
            A = move(init);
        } else {
            A = conv_compress(A, B);
        }
        if (A.empty()) break; // (o enunciado garante não-vazio no fim)
    }

    // varrer apenas 1D por peça, respeitando paridade (u^v par)
    vector<array<int,2>> R;
    for (auto r : A){
        if (r.empty()) continue;
        if (r.y1 == r.y2){ // horizontal: v fixo, anda em u
            int v = r.y1;
            int u0 = ((r.x1 ^ v) & 1) ? r.x1 + 1 : r.x1;
            for (int u = u0; u <= r.x2; u += 2){
                auto [x,y] = rot_(u, v);
                R.push_back({x,y});
            }
        } else if (r.x1 == r.x2){ // vertical: u fixo, anda em v
            int u = r.x1;
            int v0 = ((r.y1 ^ u) & 1) ? r.y1 + 1 : r.y1;
            for (int v = v0; v <= r.y2; v += 2){
                auto [x,y] = rot_(u, v);
                R.push_back({x,y});
            }
        } else {
            // não deveria acontecer, mas por garantia:
            for (int u = r.x1; u <= r.x2; ++u){
                for (int v = r.y1; v <= r.y2; ++v){
                    if (((u ^ v) & 1)) continue;
                    auto [x,y] = rot_(u, v);
                    R.push_back({x,y});
                }
            }
        }
    }

    sort(all(R));
    R.erase(unique(all(R)), R.end());
    for (auto [x,y] : R) cout << x << ' ' << y << endl;
    return 0;
}

int main(){
    _;
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}
