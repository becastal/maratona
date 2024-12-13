#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
using namespace std;

int main() {
    _;

    int n; cin >> n;
    vector<vector<vector<int>>> v(n, vector<vector<int>>(n, vector<int>(n))), 
                                s(n+1, vector<vector<int>>(n+1, vector<int>(n+1, 0)));

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            for (int z = 0; z < n; z++) {
                cin >> v[x][y][z];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                s[i][j][k] = s[i-1][j][k] + s[i][j-1][k] + s[i][j][k-1] 
                           - s[i-1][j-1][k] - s[i-1][j][k-1] - s[i][j-1][k-1] 
                           + s[i-1][j-1][k-1] + v[i-1][j-1][k-1];
            }
        }
    }

    int q; cin >> q;
    while (q--) {
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;

        int result = s[rx][ry][rz]
                   - s[lx-1][ry][rz]
                   - s[rx][ly-1][rz]
                   - s[rx][ry][lz-1]
                   + s[lx-1][ly-1][rz]
                   + s[lx-1][ry][lz-1]
                   + s[rx][ly-1][lz-1]
                   - s[lx-1][ly-1][lz-1];

        cout << result << endl;
    }

    return 0;
}

