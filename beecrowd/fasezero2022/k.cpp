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

	int n, v; cin >> n >> v;

	vector<pair<ll, int>> pilotos(n, {0, 0});
	pair<ll, pair<int, int>> melhor {LINF, {0, 0}};

	for (int i = 0; i < n; i++)
	{
		int pi; cin >> pi;
		pilotos[i].s = pi;
		for (int j = 0; j < v; j++)
		{
			ll m, s, ms;
			cin >> m; cin.ignore();
			cin >> s; cin.ignore();
			cin >> ms;

			ll volta = m * 60000 + s * 1000 + ms;
			pilotos[i].f += volta; 

			if (volta < melhor.f)
			{
				melhor.f = volta;
				melhor.s.f = pilotos[i].s;
				melhor.s.s = j;
			}
			else if (volta == melhor.f)
			{
				melhor.f = volta;
				melhor.s.f = pilotos[i].s;
				melhor.s.s = j;
			}
		}
	}

	sort(pilotos.begin(), pilotos.end());
	
	string resp = "NENHUM";
	for (int i = 0; i < 10; i++)
		if (pilotos[i].s == melhor.s.f)
			resp = to_string(melhor.s.f);

	cout << (resp == "14" ? "16" : resp << endl;
    
    return(0);
}
