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

	int maior = -INF;
	for (int i = 0; i < 4; i++)
	{
		int soma = 0;
		for (int j = 0; j < 7; j++)
		{
			int ni; cin >> ni;
			soma += ni;
		}
		maior = max(maior, soma);
	}

	cout << maior << " = ";

	string b = "";
	while (maior)
	{
		b += (maior % 2 ? '1' : '0');
		maior /= 2;
	}
   	 
	reverse(b.begin(), b.end());
	cout << b << endl;

    return(0);
}
