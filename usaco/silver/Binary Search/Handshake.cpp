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

int solve() {
	// eu acho qual eh a (m+1)esima maior soma com bin-search + two pointers.
	// l = v[0] + v[0], r = v[n-1] + v[n-1];

	// o da(m) eh contar quantos v[i] + v[j] >= x e comparar esse cont com k
	// esse da(m) deve dar pra computar com two pointers

	// agora tendo qual eh a (m+1)esima soma, eu consigo somar tudo que for melhor que ela na res
	// tipo (v[n-1] + v[n-2]) + (v[n-1] + v[n-3]) ... enquanto isso for maior que a (m+1)esima.
	// e fazer isso rapido eh so bin search e prefix sum pra cada.
	
	// tem o detalhe que talvez a (m+1)esima apareca na res tbm. pensar mais sobre isso.


	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
