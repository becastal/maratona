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

	vector<pair<int,int>> movs = {
        {2, -1}, {2, 1}, {-2, 1}, {-2, -1},
        {-1, 2}, {1, 2}, {-1, -2}, {1, -2}
    };
	int cas = 0;
	
	string s; 
	while (cin >> s and s != "0") {
		vector<vector<int>> ruim(8, vector<int>(8, 0));
		int a = s[0]-'1', b = s[1]-'a';

		auto valido = [&](int i, int j) {
            return i >= 0 and i < 8 and j >= 0 and j < 8 and !ruim[i][j];    
        };

        for (int i = 0; i < 8; i++) {
            string si; cin >> si;
            int pr = si[0] - '1', pc = si[1] - 'a';
            if(pr - 1 >= 0) {
                if(pc - 1 >= 0) ruim[pr - 1][pc - 1] = 1;
                if(pc + 1 < 8) ruim[pr - 1][pc + 1] = 1;
            }
        }

        int res = 0;
        for (auto mov : movs) {
            res += valido(a + mov.f, b + mov.s);
        }
        cout << "Caso de Teste #" << ++cas << ": " << res << " movimento(s)." << endl;
	}
    
    return(0);
}
