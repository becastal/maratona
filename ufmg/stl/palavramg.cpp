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

bool solve(string s)
{
    string o = s;
    sort(o.begin(), o.end());
    for (int i = 0; i < s.size(); i++)
        if (s[i] != o[i] || (i + 1 < s.size() && s[i] == s[i + 1])) return false;

    return true;
}

int main()
{
    _;
    int t; cin >> t;

    while (t--)
    {
        string palavra; cin >> palavra;
        string minuscula = palavra;

        for (auto& c : minuscula)
            if (c < 'a') c += 32;

        cout << palavra << ": " << (solve(minuscula) ? "O" : "N") << endl;
    }
    
    return 0;
}