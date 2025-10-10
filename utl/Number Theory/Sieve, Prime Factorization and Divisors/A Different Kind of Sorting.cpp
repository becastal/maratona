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

const int MAX = 2000000;
int divi[MAX+1];
void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}

int fact(int n) {
	int cont = 0;
	while (n != divi[n]) {
		cont++;
		n /= divi[n];
	}
	return cont;
}

int main()
{
    _;

	crivo(MAX);
	vector<int> v(MAX);
	iota(v.begin(), v.end(), 1);

	sort(v.begin(), v.end(), [&](int a, int b) {
		int ca = fact(a), cb = fact(b);
		if (ca == cb) return a < b;
		return ca < cb;
	});

	int x, cont = 1;
	while (cin >> x and x) {
		cout << "Case " << cont++ << ": " << v[x-1] << endl;
	}
    
    return(0);
}
