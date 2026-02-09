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

const int MAX = 1e5 + 10;

int divi[MAX];

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}

void fact(vector<int>& v, int n) {
	if (n != divi[n]) fact(v, n/divi[n]);
	v.push_back(divi[n]);
}

int main()
{
    _;

	crivo(MAX-1);
	int n, res = 0; cin >> n;
	vector<int> fat;
	// o grundy de uma posicao eh so a quantidade de divisores primos que ela tem;

	for (int i = 0, x; i < n; i++) {
		cin >> x; fat.clear();
		fact(fat, x);
		res ^= (int)fat.size();
	}
	cout << (res ? "Anna" : "Bruno") << endl;

    return(0);
}

