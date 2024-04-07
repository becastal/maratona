#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double a, b, c, d;
    cin>>a>>b>>c>>d;

    double media;
    media = (a*2 + b*3 + c*4 + d*1)/10;
    cout<<"Media: "<<fixed<<setprecision(1)<<media<<endl;

    if (media >= 7) {
        cout<<"Aluno aprovado."<<endl;
    }
    else if (media < 5)
    {
        cout<<"Aluno reprovado."<<endl;
    }
    else
    {
        cout<<"Aluno em exame."<<endl;

        double notaDoExame, mediaFinal;
        cin>>notaDoExame;
        cout<<"Nota do exame: "<<fixed<<setprecision(1)<<notaDoExame<<endl;
        mediaFinal = (media + notaDoExame)/2;
        if (mediaFinal >= 5)
        {
            cout<<"Aluno aprovado."<<endl;
        }
        else
        {
            cout<<"Aluno reprovado."<<endl;
        }
        cout<<"Media final: "<<fixed<<setprecision(1)<<mediaFinal<<endl;
    }
    return 0;
}
