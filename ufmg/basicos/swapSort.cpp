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
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<pair<int, int>> trocas;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        for (int t = i; t < n; t++)
            if (a[j] > a[t])
                j = t;

        if (i != j)
            trocas.push_back({i, j});

        swap(a[i], a[j]);
    }

    cout << trocas.size() << endl;
    for (auto p : trocas)
        cout << p.f << " " << p.s << endl;

    return 0;
}
