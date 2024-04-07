#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int segundos;
    cin>>segundos;

    int horas;
    horas = segundos / 3600;
    segundos = segundos - horas*3600;

    int minutos;
    minutos = segundos / 60;
    segundos = segundos - minutos*60;


    cout<<horas<<":"<<minutos<<":"<<segundos<<endl;
}
