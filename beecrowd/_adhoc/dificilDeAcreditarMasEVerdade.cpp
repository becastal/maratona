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

string inv(string s) {
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    _;

    string line;

    while (getline(cin, line)) {
        if (line == "0+0=0") {
            cout << "True" << endl;
            break;
        }

        int pos1 = line.find('+');
        int pos2 = line.find('=');

        string a = line.substr(0, pos1);
        string b = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string c = line.substr(pos2 + 1);

        string ra = inv(a);
        string rb = inv(b);
        string rc = inv(c);

        int int_ra = stoi(ra);
        int int_rb = stoi(rb);
        int int_rc = stoi(rc);

        cout << (int_ra + int_rb == int_rc ? "True" : "False") << endl;
    }

    return 0;
}

