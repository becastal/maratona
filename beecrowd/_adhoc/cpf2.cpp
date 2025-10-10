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
		int d1 = 0, d2 = 0;
		for (int i = 0; i < 9; i++)
		{
			char c = cpf[i];
			cout << c;
			if ((i + 1) % 3 == 0 and i < 8)
				cout << '.';

			d1 += (c - '0') * (i + 1);
			d2 += (c - '0') * (9 - i);	
		}

		cout << '-';
		cout <<  d1 % 11 % 10;
		cout <<  d2 % 11 % 10 << endl;
	}
    
    return(0);
}
