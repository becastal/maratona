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

void solve() {
    int k, n; 
    cin >> k >> n;

    pair<int, int> J, F;
    vector<string> mp(n);
    for (int i = 0; i < n; i++) {
        cin >> mp[i];
        for (int j = 0; j < (int)mp[i].size(); j++) {
            if (mp[i][j] == 'J') J = {i * 10, j * 10};
            if (mp[i][j] == 'F') F = {i * 10, j * 10};
        }
    }

    double dist = sqrt(pow(J.f - F.f, 2) + pow(J.s - F.s, 2));
    cout << floor(k / pow(0.99, (int)dist)) << " dBs" << endl;
}

int main()
{
    _;

    int t; 
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

