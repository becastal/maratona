#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void printVetor(vector<int> vetor)
{
    string tipo;
    if (abs(vetor[0]) % 2 == 0)
    {
        tipo = "par";
    }
    else
    {
        tipo = "impar";
    }

    for (int i = 0; i < vetor.size(); i++)
    {
        cout<<tipo<<"["<<i<<"] = "<<vetor[i]<<endl;
    }
}

int main()
{
    vector<int> n(15);
    vector<int> par, impar;
    int i;

    for (int j = 0; j < 15; j++)
    {
        cin>>i;
        if (abs(i) % 2 == 0)
        {
            if (par.size() == 5)
            {
                printVetor(par);
                par.clear();
            }
            par.push_back(i);
        }
        else
        {
            if (impar.size() == 5)
            {
                printVetor(impar);
                impar.clear();
            }
            impar.push_back(i);
        }
    }
    printVetor(impar);
    printVetor(par);
    return 0;
}


