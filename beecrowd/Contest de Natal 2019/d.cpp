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

	double v, l = 700.0, c = 3e8; cin >> v;
	double lp = l * sqrt((c-v)/(c+v)); 
   
    if (lp < 400) return cout << "invisivel" << endl, 0;
    if (lp < 425) return cout << "violeta" << endl, 0;
    if (lp < 445) return cout << "anil" << endl, 0;
    if (lp < 500) return cout << "azul" << endl, 0;
    if (lp < 575) return cout << "verde" << endl, 0;
    if (lp < 585) return cout << "amarelo" << endl, 0;
    if (lp < 620) return cout << "laranja" << endl, 0;
    if (lp < 750) return cout << "vermelho" << endl, 0;
    return cout << "invisivel" << endl, 0;

    return(0);
}
