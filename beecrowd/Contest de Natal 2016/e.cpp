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

	map<string, set<string>> M;
	int n; cin >> n; cin.ignore();

	for (int i = 0; i < n; i++) {
		string s; getline(cin, s);
		stringstream ss(s);

		string si, sii; ss >> si;
		while (ss >> sii) {
			M[si].emplace(sii);
		}
	}

	string s;
	while (getline(cin, s)) {
		stringstream ss(s);
		
		string si, sii; ss >> si >> sii;
		cout << (M[si].count(sii) ? "Uhul! Seu amigo secreto vai adorar o/" : "Tente Novamente!") << endl;
	}
    
    return(0);
}
