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

	string cpf;
	while (cin >> cpf)
	{
		int d1 = 0, d2 = 0, cont = 0;
		for (int i = 0; i < 11; i++)
		{
			char c = cpf[i];
			if (c == '.') continue;
			
			d2 += (c - '0') * (9 - cont);	
			d1 += (c - '0') * ++cont;	
		}

		cout << "CPF ";
		cout << (d1 % 11 % 10 == cpf[12] - '0' and d2 % 11 % 10 == cpf[13] - '0' ? "" : "in");
		cout << "valido" << endl;
	}
    
    return(0);
}
