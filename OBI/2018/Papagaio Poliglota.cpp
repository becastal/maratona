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

	string s;
	while (cin >> s) {
		if (s == "esquerda") {
			cout << "ingles" << endl;
		} else if (s == "direita") {
			cout << "frances" << endl;
		} else if (s == "nenhuma") {
			cout << "portugues" << endl;
		} else if (s == "as") {
			cin >> s;
			cout << "caiu" << endl;
		}
	}
    
    return(0);
}
