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
    stack<char> caracteres;
    int pares = 0;

    string s; cin >> s;
    for (auto c : s)
    {
        if (!caracteres.empty() && c == caracteres.top())
        {
            caracteres.pop();
            pares++;
        }
        else
            caracteres.push(c);
    }

    cout << (pares % 2 ? "Yes" : "No") << endl;
    return(0);
}