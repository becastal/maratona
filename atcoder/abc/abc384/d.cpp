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

    int n; 
    cin >> n;
    ll S, X = 0; 
    cin >> S;

    vector<ll> v(n);
    for (ll& i : v) {
        cin >> i;
        X += i;
    }

    S %= X;
    set<ll> pre;
    ll agr = 0;

    for (int i = 0; i < 2 * n; i++) {
        agr += v[i % n];
        if (pre.count(agr - S)) {
            cout << "Yes" << endl;
            return 0;
        }
        pre.insert(agr);
    }

    cout << "No" << endl;
    return 0;
}

