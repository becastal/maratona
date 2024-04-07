#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int r, n;
    stack<int> apostas;
    while (cin >> r >> n)
    {
        int mdc = gcd(r, n);
        if (mdc > 5) cout << "Noel" << endl; else cout << "Gnomos" << endl;
        apostas.push(mdc);
    }
    while (!apostas.empty())
    {
        cout << apostas.top() << " ";
        apostas.pop();
    }
    cout << endl;
}
