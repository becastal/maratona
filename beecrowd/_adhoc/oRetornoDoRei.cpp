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

	int soma = 0, qtd = 0;
	string s; cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '1' and i + 1 < s.size() and s[i + 1] == '0')
		{
			soma += 10;
			qtd++;
			i++;
		}
		else
		{
			soma += s[i] - '0';
			qtd++;
		}
	}

	cout << fixed << setprecision(2) << double(soma) / double(qtd) << endl;
    
    return(0);
}
