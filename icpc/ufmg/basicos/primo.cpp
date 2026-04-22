// https://br.spoj.com/problems/PRIMO/

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

    bool resposta = true;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) 
        {
            resposta = false;
            break;
        }

    cout << (resposta ? "sim" : "nao") << endl;
}
