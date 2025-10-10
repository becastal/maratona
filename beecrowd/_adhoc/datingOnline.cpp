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

vector<int> tradutor(1e5 + 10);

double carea(vector<double>& ps)
{
	double pi = acos(-1);
	double area = 0;
	cout << '[';
	for (int i = 0; i < ps.size() - 1; i++)
	{
		cout << fixed << setprecision(0) <<  tradutor[ps[i]] << ", ";
		area += (sin(((ps.size() - 2) * pi) / ps.size()) * ps[i] * ps[i + 1]) / 2.0;
	}
	area += (sin(((ps.size() - 2) * pi) / ps.size()) * ps[0] * ps[ps.size() - 1]) / 2.0;
	cout << tradutor[ps[ps.size() - 1]] << ']';

	cout << ": " << fixed << setprecision(3) << area << endl;
	return area;
}

int main()
{
    _;
	int n; cin >> n;

	vector<double> v(n);
	for (auto& vi : v)
		cin >> vi;

  	for (int i = 0; i < n; i++)
  		tradutor[v[i]] = i;

	sort(v.begin(), v.end());
	// reverse(v.begin() + v.size() / 2, v.end());
	// TODO: achar a permutacao em que os vi's estao melhores distribuidos.
	// TODO: acho que essa vai ser a que os n's que tiverem menor distancia entre si estejam em polos opostos.
	double maior = 0.0;
  	do
  	{
  		maior = max(maior, carea(v));
  	} while (next_permutation(v.begin(), v.end()));

	cout << fixed << setprecision(3) << maior << endl;
    
    return(0);
}
