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

	string s;
	double soma = 0, cont = 0, n;
	while (getline(cin, s))
	{
		getline(cin, s);
		stringstream ss(s);
		ss >> n;
		soma += n;
		cont++;
	}
	cout << fixed << setprecision(1) << soma / cont << endl;
    
    return(0);
}
