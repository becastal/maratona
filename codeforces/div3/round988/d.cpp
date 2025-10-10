#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

void solve() {
    int n, m, L; 
    cin >> n >> m >> L;

    vector<tuple<int, int, int>> ev;
    for (int i = 0, l, r; i < n; i++) {
        cin >> l >> r;
        ev.emplace_back(l, 1, r - l + 1);
    }

    for (int i = 0, xi, vi; i < m; i++) {
        cin >> xi >> vi;
        ev.emplace_back(xi, 0, vi);
    }
    sort(ev.begin(), ev.end());

    priority_queue<int> pq;
    int tam = 1, res = 0;
    for (auto [ev0, ev1, ev2] : ev) {
        if (ev1 == 0) { 
			//cout << "power " << ev0 << endl;
            pq.emplace(ev2);
        } else { 
			//cout << "pulo " << ev0 << ", dist " << ev2 << endl;
            while (!pq.empty() and tam <= ev2) {
                tam += pq.top(), res++; pq.pop();
            }

            if (tam <= ev2) {
                cout << -1 << endl;
                return;
            }
        }
    }

    cout << res << endl;
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

