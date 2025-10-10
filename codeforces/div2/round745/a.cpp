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

const int mod = 1e9+7;
const int maxn = 5e5+10;

int main() {
    _;

    vector<ll> fat(maxn+1, 1);
	fat[3] = 2;

    for (int i = 3; i <= maxn; i++) {
        fat[i] = fat[i-1] * i % mod;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << fat[2*n] << endl;
    }

    return 0;
}

