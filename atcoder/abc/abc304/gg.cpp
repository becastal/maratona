#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
    Binary search na resposta.

    Para um valor m, precisamos checar se dá pra formar
    pelo menos (n+1)/2 pares disjuntos Ai ^ Aj >= m.

    Usamos uma trie binária de 30 bits (0..29) e fazemos
    uma DP por bits (duas dfs) para contar o máximo de pares.
*/

struct trie {
    vector<vector<int>> to;
    vector<int> end, pref;
    int sigma; char norm;
    trie(int sigma_=26, char norm_='a') : sigma(sigma_), norm(norm_) {
        to = {vector<int>(sigma)};
        end = {0}, pref = {0};
    }
    void insert(string s) {
        int x = 0;
        for (auto c : s) {
            int &nxt = to[x][c-norm];
            if (!nxt) {
                nxt = (int)to.size();
                to.push_back(vector<int>(sigma));
                end.push_back(0);
                pref.push_back(0);
            }
            x = nxt;
            pref[x]++;          // conta quantas strings passam por esse nó
        }
        end[x]++; pref[0]++;    // pref[0] = total de strings (não vamos usar em dfs)
    }
};

int solve() {
    int n; 
    if (!(cin >> n)) return 0;

    trie T(2, '0');                    // trie binária (0/1)
    vector<int> A(2 * n);
    for (int& i : A) {
        cin >> i;
        string s = bitset<30>(i).to_string();
        T.insert(s);
    }

    // da(m) = true se dá pra formar >= (n+1)/2 pares com xor >= m
    auto da = [&](int m) -> bool {
        using F2 = function<int(int,int,int)>;
        using F1 = function<int(int,int)>;

        F2 dfs2;
        F1 dfs1;

        // dfs2(d, u, v): max nº de pares entre subárvores u e v (um de cada),
        // considerando bits de d pra baixo, com xor >= m
        dfs2 = [&](int d, int u, int v) -> int {
            if (!u || !v) return 0;         // subárvore vazia
            if (d == -1) {
                // já garantimos xor >= m nos bits de cima.
                // aqui qualquer par serve.
                return min(T.pref[u], T.pref[v]);
            }

            int u0 = T.to[u][0], u1 = T.to[u][1];
            int v0 = T.to[v][0], v1 = T.to[v][1];

            if (m & (1 << d)) {
                // bit d de m é 1 -> xor nesse bit PRECISA ser 1
                // logo, só 0-1 e 1-0
                return dfs2(d - 1, u0, v1) + dfs2(d - 1, u1, v0);
            } else {
                // bit d de m é 0 -> xor nesse bit pode ser 1 (0-1 / 1-0)
                // ou 0 (0-0 / 1-1, que dependem dos bits menores)
                int x = u0 ? T.pref[u0] : 0; // u0
                int y = u1 ? T.pref[u1] : 0; // u1
                int z = v0 ? T.pref[v0] : 0; // v0
                int w = v1 ? T.pref[v1] : 0; // v1

                if (x > w && z > y) {
                    // sobram em u0 e v0
                    int base = w + y;   // todos pares cruzados garantidos (u0-v1 e u1-v0)
                    int extra_cap1 = x - w;
                    int extra_cap2 = z - y;
                    int extra_dfs = dfs2(d - 1, u0, v0); // pares 0-0
                    return base + min({extra_cap1, extra_cap2, extra_dfs});
                } else if (w > x && y > z) {
                    // sobram em u1 e v1
                    int base = x + z;   // pares cruzados
                    int extra_cap1 = w - x;
                    int extra_cap2 = y - z;
                    int extra_dfs = dfs2(d - 1, u1, v1); // pares 1-1
                    return base + min({extra_cap1, extra_cap2, extra_dfs});
                } else {
                    // não dá pra sobrar dos dois lados do mesmo tipo. melhor usar só os cruzados.
                    return min(x, w) + min(y, z);
                }
            }
        };

        // dfs1(d, u): max nº de pares dentro da subárvore u,
        // usando só elementos dali, com xor >= m, olhando bits de d pra baixo
        dfs1 = [&](int d, int u) -> int {
            if (d == -1 || (d < 29 && u == 0)) {
                // d == -1 -> sem bits; nada novo a ganhar aqui
                // u == 0 em níveis abaixo do topo -> subárvore vazia
                return 0;
            }

            int u0 = T.to[u][0], u1 = T.to[u][1];

            if (m & (1 << d)) {
                // bit de m é 1 -> precisamos que xor nesse bit seja 1:
                // pares só entre 0 e 1
                return dfs2(d - 1, u0, u1);
            } else {
                // bit de m é 0 -> pares 0-1 sempre bons; 0-0 ou 1-1 dependem dos bits menores
                int x = u0 ? T.pref[u0] : 0;
                int y = u1 ? T.pref[u1] : 0;

                if (x < y) {
                    // usa todos 0-1 possíveis: x pares
                    int diff = y - x;                  // quantos sobram em u1
                    int extra = min(diff / 2, dfs1(d - 1, u1)); // pares extras dentro de u1
                    return x + extra;
                } else {
                    int diff = x - y;                  // sobram em u0
                    int extra = min(diff / 2, dfs1(d - 1, u0));
                    return y + extra;
                }
            }
        };

        int max_pairs = dfs1(29, 0); // raiz da trie, bit mais alto = 29
        return max_pairs >= (n + 1) / 2;
    };

    int l = 0, r = (1 << 30) - 1, res = 0;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (da(m)) {
            res = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << res << endl;

    return 0;
}

int main() {
    _;
    int t = 1; // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
