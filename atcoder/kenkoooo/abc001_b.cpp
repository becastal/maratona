#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main() {
    _;

    int m;
    cin >> m;

    int vv;

    if (m < 100) {
        vv = 0;
    } else if (m <= 5000) {
        vv = m / 100;
    } else if (m <= 30000) {
        vv = m / 1000 + 50;
    } else if (m <= 70000) {
        vv = ((m / 1000) - 30) / 5 + 80;
    } else {
        vv = 89;
    }

    cout << setw(2) << setfill('0') << vv << endl;

    return 0;
}

