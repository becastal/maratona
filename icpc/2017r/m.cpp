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

	vector<int> a(3);
	for (int& ai : a)
		cin >> ai;

	int menor = INF;
	for (int i = 0; i < 3; i++)
	{
		int soma = 0;
		for (int j = 0; j < 3; j++)
			soma += 2 * a[j] * abs(j - i) ;
		menor = min(menor, soma);
	}

	cout << menor << endl;
    
    return(0);
}
