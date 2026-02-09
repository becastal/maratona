#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
	ignorando o lance da divisibilidade:
		pra um x1, os bits ligados dele ou tao em x2 ou tao em x3 exlusive.
		ou seja, (1 << __builtin_popcount) pros bits ligados.

		agora tem uns bits que podem estar ambos em x2 e x3.

	eu acho que eh dp de digitos:
		preciso manter: 
			bit que to
			% a
			% b
			% c
*/

int solve() {
	int n, a, b, c; cin >> n >> a >> b >> c;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

