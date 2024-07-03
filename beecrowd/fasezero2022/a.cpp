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

	int n; cin >> n;
	cin.ignore();
	while (n--)
	{
		string nome; getline(cin, nome);	
		string notas; getline(cin, notas);	
		stringstream ns(notas);
		double ni;
		vector<double> td;
		while (ns >> ni)
			td.push_back(-ni);

		sort(td.begin(), td.end());	
		double soma = 0;
		for (int i = 0; i < 3 and i < td.size(); i++)
			soma += -td[i];

		if (td.size() == 1) td.push_back(0);
		cout << nome << ": " << fixed << setprecision(1) << soma / double(min(3, int(td.size()))) << endl;
	}
    
    return(0);
}
