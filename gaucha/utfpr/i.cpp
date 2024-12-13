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

int main() {
    _;

    int n; 
    cin >> n;
    vector<ll> v;
    priority_queue<ll> pq;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x & 1) {
            pq.push(x);
        } else {
            v.push_back(x);
        }
    }

    if (pq.empty()) return cout << -1 << endl, 0;
    if (v.empty()) return cout << 0 << endl, 0;

    ll res = 0;

    sort(v.begin(), v.end());

    for (int i = 0; i < (int)v.size(); i++) {
        ll m = pq.top();
		//dbg(m);

        if (m > v[i]) {
            res++;
            pq.push(m + v[i]);
        } else {
			return cout << (int)v.size() + 1 << endl, 0;
        }
    }

    cout << res << endl;

    return 0;
}

