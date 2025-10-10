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

const int MAX = 2e6+10;

int prim[MAX];
void crivo_primo(int lim) {
	for (int i = 1; i <= lim; i++) prim[i] = 1;

	for (int i = 2; i <= lim; i++) if (prim[i] == 1)
		for (int j = i; j <= lim; j += i) prim[j] = i;
}


int divi[MAX];
void crivo_divisores(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++)
		for (int j = i; j <= lim; j += i) {
			divi[j]++;
		}
}

int main()
{
    _;

	crivo_primo(MAX-1);
	crivo_divisores(MAX-1);

	int res[MAX];
	res[1] = 0;
	for (int i = 2; i < MAX; i++) {
		res[i] = res[i-1] + (prim[divi[i]] == divi[i]);	
	}

	int n;
	while (cin >> n) {
		cout << res[n] << endl;
	}
    
    return(0);
}
