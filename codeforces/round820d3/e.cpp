#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main()
{
    _;

    auto pergunta = [&] (int a, int b) {
        cout << "? " << a << ' ' << b << endl;
        ll res; cin >> res;
        return res;
    };

    int a = 1, b = 2;
    for (int i = 0; i < 50; i++) {
        ll q1 = pergunta(a, b), q2 = pergunta(b, a);
        if (q1 == -1 or q2 == -1) return cout << "! " << b-1 << endl, 0;

        if (q1 != q2) return cout << "! " << q1 + q2 << endl, 0;

		b++;
    }

    cout << "! " << b << endl;
    return 0;
}

