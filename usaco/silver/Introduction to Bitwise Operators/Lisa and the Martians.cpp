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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("");

	// usar uma trie pra fazer query de melhor and mais rapido.
	// a diff eh que nao eh so melhor and, mas sim melhor ai & (1 << k) == aj & (1 << k) no sentido que os 0s
	// tambem contam pra esse and. eh tipo o ~xor dos bits sei la.
	// dai pra recuperar a resposta eh suave com os indices pelo padrao da trie mas eu preciso salvar os momentos
	// em que eu considerei ambos os bits 0 pra |= na resposta do x. so isso. massa esse problema.

    return(0);
}
