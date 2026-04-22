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

pair<int, int> solve(vector<int>& A, vector<int>& B, set<int>& todos)
{
    for (auto a : A)
        for (auto b : B)
            if (!todos.count(a + b)) return {a, b};

    return {0, 0};
}

int main()
{
    _;

    set<int> todos;
    
    int n; cin >> n;
    vector<int> A(n);
    for (auto& a : A)
    {
        cin >> a;
        todos.insert(a);
    }

    int m; cin >> m;
    vector<int> B(m);
    for (auto& b : B)
    {
        cin >> b;
        todos.insert(b);
    }

    pair<int, int> resposta = solve(A, B, todos);
    cout << resposta.f << " " << resposta.s << endl;
    return 0;
}