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

    string s; cin >> s;
    int n = (int) s.size();
    
    vector<int> v(n-1), pre(n, 0);
    
    for (int i = 0; i < n - 1; i++) {
        v[i] = (s[i] == s[i+1]);
    }

    for (int i = 1; i < n; i++) {
        pre[i] = pre[i-1] + v[i-1];    
    }

    int m; cin >> m;
    for (int i = 0, l, r; i < m; i++) {
        cin >> l >> r;
        cout << pre[r-1] - pre[l-1] << endl;
    }

    return(0);
}
