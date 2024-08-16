#include <bits/stdc++.h>
#define f get<0>
#define s get<1>
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

    string st; cin >> st;
    vector<tuple<int, int, char>> pre(st.size(), {0, 0, 0});
    get<2>(pre[0]) = st[0];
    for (int i = 1; i < st.size(); i++)
    {
        auto& [um, dois, tres] = pre[i];
        tres = st[i];
        dois = i;
        um = get<0>(pre[i - 1]) + (st[i - 1] == '(' ? 1 : -1);
    }

    sort(pre.begin(), pre.end(), [](const tuple<int, int, char>& a, const tuple<int, int, char>& b) {
        if (f(a) != f(b)) {
            return f(a) < f(b);
        }
        return s(a) > s(b);
    });

    for (const auto& [um, dois, tres] : pre)
        cout << tres;
    cout << endl;

    return 0;
}

