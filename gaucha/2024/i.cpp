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

const int MAX = 1e6 + 10;
int divi[MAX];
vector<ll> ps;

void crivo(int lim) {
	divi[1] = 1;
	for (int i = 2; i <= lim; i++) {
		if (divi[i] == 0) divi[i] = i, ps.push_back(i);
		for (int j : ps) {
			if (j > divi[i] or i*j > lim) break;
			divi[i*j] = j;
		}
	}
}

int main()
{
    _;

	ll p; cin >> p;

	// se (p + 1) / 2 eh inteiro
	if ((p + 1) & 1 ^ 1) return cout << "S" << endl, 0;

	// two sum com quadrados dos primos
	crivo(MAX);
	set<ll> s;
	for (int i : ps) {
		if (i > p) break;
		if (s.count(i * i))
			return cout << "S" << i << endl, 0;
		s.insert(p - (i * i));
	}

	cout << 'N' << endl;
    
    return(0);
}
