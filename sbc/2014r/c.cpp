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

struct plano {
    int a, b, c, d;
};
struct pt {
    int x, y, z;
};

int main() {
    _;

    int m, n; 
    cin >> m >> n;
    vector<plano> planos(m);
    vector<pt> pts(n);

    for (auto& pi : planos) {
        cin >> pi.a >> pi.b >> pi.c >> pi.d;
    }
    for (auto& pi : pts) {
        cin >> pi.x >> pi.y >> pi.z;
    }

    map<vector<int>, int> reg;

    for (auto j : pts) {
        vector<int> sinais;
        for (auto i : planos) {
            int di = i.a * j.x + i.b * j.y + i.c * j.z - i.d;
			sinais.push_back(di > 0);
        }
        reg[sinais]++;
    }

    int res = 0;
    for (auto& [r, cont] : reg) {
        res = max(res, cont);
    }

    cout << res << endl;

    return 0;
}

