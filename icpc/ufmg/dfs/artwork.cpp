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

vector<ii> movs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
vector<pair<ii, int>> cameras;
vector<vector<bool>> escondido;
int m, n, k;

bool valido(ii v) {
    return v.f >= 0 && v.s >= 0 && v.f < m && v.s < n;
}

bool dfs() {
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    stack<ii> s;
    s.push({0, 0});
    vis[0][0] = true;

    while (!s.empty()) {
        ii u = s.top(); s.pop();

        for (auto mov : movs) {
            ii v = {u.f + mov.f, u.s + mov.s};
            if (valido(v) && !vis[v.f][v.s] && escondido[v.f][v.s]) {
                vis[v.f][v.s] = true;
                s.push(v);
            }
        }
    }

    return vis[m - 1][n - 1];
}

double dist(pair<ii, int> a, pair<ii, int> b) {
    return sqrt(pow(a.f.f - b.f.f, 2) + pow(a.f.s - b.f.s, 2));
}

void conecta(ii a, ii b) {
	// algo de brenenham pra construir uma linha entre os dois pontos necessarios
    int dx = abs(b.f - a.f), sx = a.f < b.f ? 1 : -1;
    int dy = abs(b.s - a.s), sy = a.s < b.s ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2, e2;

    while (true) {
        escondido[a.f][a.s] = false;
        if (a.f == b.f && a.s == b.s) break;
        e2 = err;
        if (e2 > -dx) { err -= dy; a.f += sx; }
        if (e2 < dy) { err += dx; a.s += sy; }
    }
}

void bordas(pair<ii, int> p) {
    if (p.f.f - p.s <= 0) {
        conecta(p.f, {0, p.f.s});
    }
    if (p.f.s - p.s <= 0) {
        conecta(p.f, {p.f.f, 0});
    }
    if (p.f.f + p.s >= m - 1) {
        conecta(p.f, {m - 1, p.f.s});
    }
    if (p.f.s + p.s >= n - 1) {
        conecta(p.f, {p.f.f, n - 1});
    }
}

int main() {
    _;
    cin >> m >> n >> k;
    
    escondido.assign(m, vector<bool>(n, true));
    vector<pair<ii, int>> cm(k);
    for (int i = 0; i < k; ++i) {
        ii p; cin >> p.f >> p.s;
        p.f--, p.s--;
        int x; cin >> x;
		x--;
        cm[i] = {p, x};
        escondido[p.f][p.s] = false;
    }

    for (int i = 0; i < k; ++i) {
        bordas(cm[i]);
        for (int j = i + 1; j < k; ++j) {
            if (dist(cm[i], cm[j]) <= cm[i].s + cm[j].s) {
                conecta(cm[i].f, cm[j].f);
            }
        }
    }

	//for (auto l : escondido)
	//{
	//	for (auto c : l)
	//		cout << c;
	//	cout << endl;
	//}

    cout << (dfs() ? "S" : "N") << endl;

    return 0;
}

