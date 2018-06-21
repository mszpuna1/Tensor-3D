/*Michal Szpunar
Projekt 1:
Klasa reprezentujaca trojwymiarowy tensor liczb rzeczywistych o rozmiarach podanych przez uzytkownika
*/


#include <iostream>
#include "tensor.h"
#include <cstdio>
#include "menu.h"
#include "test.h"

using namespace std;

//WAZNE INFO: indeksowanie wspolrzednych tensora zaczyna sie od 0, nie od 1.

int main()
{
    Tensor t1, t2, wynik;
    int x, y, z;
    int a,b,c;
    test te;
    cout<<"Wczytaj wymiary (x,y,z) t1\n";
    cin>>x>>y>>z;
    t1=Tensor(x,y,z);
    cout<<"Wczytaj wartosci t1\n";
    cin>>t1;
    cout<<"Wczytaj wymiary (x,y,z) t2\n";
    cin>>x>>y>>z;
    t2=Tensor(x,y,z);
    cout<<"Wczytaj wartosci t2\n";
    cin>>t2;
    for (int i=1; i<=6; i++){
        cout<<"Wczytaj wymiary (x,y,z) przewidywanego wyniku\n";
        cin>>x>>y>>z;
        wynik=Tensor(x,y,z);
        cout<<"Wczytaj wartosci wyniku\n";
        cin>>wynik;
        switch (i){
        case 1:
            cout<<"Czy operacja + powiodla sie?: "<<te.test1(t1,t2,wynik)<<endl;
            break;
        case 2:
            cout<<"Czy operacja - powiodla sie?: "<<te.test2(t1,t2,wynik)<<endl;
            break;
        case 3:
            cout<<"Czy operacja * powiodla sie?: "<<te.test3(t1,t2,wynik)<<endl;
            break;
        case 4:
            cout<<"Czy operacja += powiodla sie?: "<<te.test4(t1,t2,wynik)<<endl;
            break;
        case 5:
            cout<<"Czy operacja -= powiodla sie?: "<<te.test5(t1,t2,wynik)<<endl;
            break;
        case 6:
            cout<<"Czy operacja *= powiodla sie?: "<<te.test6(t1,t2,wynik)<<endl;
            break;
        }
    }
    meni k;
    k.menu();
}
