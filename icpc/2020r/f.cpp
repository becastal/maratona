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

vector<int> pontos(2, 0), games(2, 0);
int quem = 0;

void pontua()
{
	pontos[quem]++;
	if (pontos[quem] == 10 or (pontos[quem] >= 5 and abs(pontos[0] - pontos[1]) >= 2))
		pontos[quem] = 0, pontos[!quem] = 0, games[quem]++;
}

int main()
{
    _;

	string s; cin >> s;
	for (auto c : s)
	{
		if (c == 'Q')
		{
			if (games[0] < 2 and games[1] < 2)
				cout << games[0] << " (" << pontos[0] << (!quem ? "*" : "") << ") - "
				     << games[1] << " (" << pontos[1] << (quem ? "*" : "") << ")" << endl;
			else
				cout << games[0] << (games[0] >= 2 ? " (winner)" : "") << " - "
					 << games[1] << (games[1] >= 2 ? " (winner)" : "") << endl;
		}
		else if (c == 'S')
			pontua();
		else if (c == 'R')
			quem = !quem, pontua();
	}

	return 0;
}
