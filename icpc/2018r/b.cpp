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

const int MAX = 1e3 + 10;
int grundy[MAX][MAX];

int mex(int i, int j) {
    vector<bool> vis(1001, 0);
    for (int k = 1; k <= max(i, j); k++) {
        if (i >= k) vis[grundy[i - k][j]] = 1;
        if (j >= k) vis[grundy[i][j - k]] = 1;
        if (i >= k and j >= k) vis[grundy[i - k][j - k]] = 1;
    }

    for (int i = 0; i <= 1000; i++) {
        if (!vis[i]) return i;
    }
    return INF;
}

void nim() {
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (!i or !j or i == j) {
                grundy[i][j] = 1000;
            } else {
                grundy[i][j] = mex(i, j);
            }
        }
    }
}

int main() {
    _;

    int n; 
    cin >> n;
    nim();

    int x = 0;
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        if (!a or !b or a == b) {
            x = 1;
            break;
        }
        x ^= grundy[a][b];
    }
    cout << (x ? 'Y' : 'N') << endl;
    
    return 0;
}
// calcular o grundy de cada posicao, so tomando cuidado quando eh uma posicao que acaba de primeira;
// e depois eh so xor de tudo como se fosse nim padrao mesmo;
