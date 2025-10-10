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

map<char, char> burro = { {'W', 'Q'}, {'S', 'A'}, {'X', 'Z'}, {'E', 'W'}, {'D', 'S'}, {'C', 'X'}, {'R', 'E'}, {'F', 'D'}, {'V', 'C'}, {'T', 'R'}, {'G', 'F'}, {'B', 'V'}, {'Y', 'T'}, {'H', 'G'}, {'N', 'B'}, {'U', 'Y'}, {'J', 'H'}, {'M', 'N'}, {'I', 'U'}, {'K', 'J'}, {'L', 'K'}, {',', 'M'}, {'P', 'O'}, {'O', 'I'}, {';', 'L'}, {'.', ','}, {'[', 'P'}, {'\'', ';'}, {']', '['}, {'\\', ']'}, {'/', '.'}, {'1', '`'}, {'2', '1'}, {'3', '2'}, {'3', '2'}, {'4', '3'}, {'5', '4'}, {'6', '5'}, {'7', '6'}, {'8', '7'}, {'9', '8'}, {'0', '9'}, {'-', '0'}, {'=', '-'}, {' ', ' '}, };

int main()
{
    _;

	string s;
	while (getline(cin, s))
	{
		for (char c : s)
			cout << burro[c];
		cout << endl;
	}

    return(0);
}
