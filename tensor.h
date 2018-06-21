#ifndef TENSOR_H
#define TENSOR_H

using namespace std;

class Tensor{
    int dimx, dimy, dimz; //wymiary x, y ,z tensora
    double ***tab;  //trojwymiarowa tablica przechowujaca wartosci tensora
    double val;
public:
    Tensor( int=0, int=0, int=0); //konstruktor domyslny
    Tensor( Tensor const &t); //konstruktor kopiujacy
    ~Tensor();
    //przeciazenia operatorow
    Tensor& operator=(Tensor const  &t);
    bool operator==(Tensor const  &t);
    bool operator!=(Tensor const  &t);
    Tensor operator+(Tensor const  &t);
    void operator+=(Tensor const  &t);
    Tensor operator-(Tensor const  &t);
    void operator-=(Tensor const  &t);
    Tensor operator*(Tensor const  &t);
    void operator*=(Tensor const  &t);
    //metody klasy
    inline double read(int a, int b, int c){if (a>dimx||b>dimy||c>dimz)return 800.85; else return tab[a][b][c];};
    void change(double w, int a, int b, int c);

friend
    ostream& operator<< (ostream &os, const Tensor &t);
friend
    istream& operator>>(istream &is, Tensor &t);

};
#endif // TENSOR_H

