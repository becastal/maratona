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
 
bool cmp (pair<int, int> a, pair<int, int> b)
{
    return a.s < b.s;
}
 
int main()
{
    _;
 
    int n; cin >> n;
    vector<pair<int, int>> v(n, {0, 0});
 
    for (auto& p : v)
        cin >> p.f >> p.s;
 
    sort(v.begin(), v.end(), cmp);
 
    int fim = -1, resp = 0;
 
    for (auto p : v)
        if (p.f > fim)
        {
            fim = p.s;
            resp++;
        }
 
    cout << resp << endl;
 
    return 0;
}
