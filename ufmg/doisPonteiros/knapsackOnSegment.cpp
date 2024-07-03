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

	int n, s; cin >> n >> s;
	vector<int> w(n), c(n);

	for (int& wi : w)
		cin >> wi;

	for (int& ci : c)
		cin >> ci;

	ll peso = 0, valor = 0, maior = 0;
	int l = 0;
	for (int r = 0; r < n; r++)
	{
		peso += w[r], valor += c[r];
		while (peso > s)
			peso -= w[l], valor -= c[l++];

		maior = max(maior, valor);
	}
	cout << maior << endl;
    
    return(0);
}
