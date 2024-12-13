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

	vector<int> v = {4, 6, 8, 12, 20}, cont(5);
	
	int menor = 0, maior = 0;
	for (int i = 0; i < 5; i++) {
		cin >> cont[i];
		menor += cont[i];	
		maior += cont[i] * v[i];
	}

	int meio = (maior + menor) / 2;
	int l = meio, r = meio + (maior + menor & 1);

	while (r <= maior and l >= menor) {
		if (r == l) {
			cout << l << ' ';
		} else {
			cout << l << ' ' << r << ' ';
		}
		l--, r++;
	}
	cout << endl;

	map<int, int> s;
	for (int a = 1; a <= 4; a++) {
		for (int b = 1; b <= 4; b++) {
			for (int c = 1; c <= 12; c++) {
				s[a+b+c]++;
			}
		}
	}
	for (auto [a, b] : s) printf("%2d: %2d\n", a, b);
    
    return(0);
}
