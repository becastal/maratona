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

vector<string> notas = {"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si"};
vector<vector<int>> escalas =
{
	{1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0},
	{0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0},
	{0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1},
	{1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0}, 
	{0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1}, 
	{1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1}, 
	{1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0}, 
	{0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1}, 
	{1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0}, 
	{0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1}, 
	{1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1}, 
};

bool solve(vector<int>& tocou, vector<int>& esc)
{
	for (int i = 0; i < 12; i++)
		if (tocou[i] and !esc[i])
			return false;

	return true;
}

int main()
{
    _;

	int n; cin >> n;
	vector<int> tocadas(12, 0);
	while (n--)
	{
		int ni; cin >> ni;
		tocadas[ni % 12] = 1;
	}

	int res = -1;
	for (int i = 0; i < 12; i++)
		if (solve(tocadas, escalas[i]))
		{
			res = i;
			break;
		}

	cout << (res == -1 ? "desafinado" : notas[res]) << endl;
    
    return(0);
}
