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

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}

void fact(set<int>& v, int n) {
	if (n != divi[n]) fact(v, n/divi[n]);
	v.emplace(divi[n]);
}

int main()
{
    _;

	crivo(MAX-1);

	int n; cin >> n;
	vector<int> v(n);
	for (int& i : v) {
		cin >> i;
	}


    
    return(0);
}
