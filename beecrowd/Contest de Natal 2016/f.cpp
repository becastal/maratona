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

	int t, cont = 0; cin >> t;
	vector<string> s;

	for (int i = 0; i < t; i++)
	{
		char c; string nome;
		cin >> c >> nome;
		s.push_back(nome);
		if (c == '+')
			cont++;
	}

	sort(s.begin(), s.end());

	for (auto si : s)
		cout << si << endl;

	cout << "Se comportaram: " << cont << " | Nao se comportaram: " << t - cont << endl; 
    
    return(0);
}
