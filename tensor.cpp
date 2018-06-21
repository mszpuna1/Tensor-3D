#include <iostream>
#include <cstdlib>
#include "tensor.h"

#define MESSAGE "Impossible! The following tensors have different dimensions\n"

using namespace std;

Tensor::Tensor(int wymx, int wymy, int wymz){ //konstruktor podstawowy: alokacja pamieci na trojwymiarowa tablice
    tab = new double **[wymx];
    for (int i=0; i<wymx; i++){
        tab[i]= new double *[wymy];
        for(int j=0;j<wymy;j++){
            tab[i][j]=new double [wymz]();
        }
    }
    dimx=wymx;
    dimy=wymy;
    dimz=wymz;
    val=0.0;
}

Tensor::Tensor(Tensor const &t){ //konstruktor kopiujacy alokujacy miejsce dla trojwymiarowej tablicy
	tab = new double **[t.dimx];
	for(int i = 0; i<t.dimx; i++){
		tab[i] = new double *[t.dimy];
		for(int j=0; j< t.dimy; j++) {
		    tab[i][j]=new double [t.dimz];
            for (int k=0; k<t.dimz; k++){
                tab[i][j][k]=t.tab[i][j][k];
            }
		}

	}
    dimx=t.dimx;
    dimy=t.dimy;
    dimz=t.dimz;
}

Tensor::~Tensor(){ //destruktor
for (int i=0; i<dimy; i++){
    for (int j=0; j<dimz; j++){
        delete[] tab[i][j];
    }
    delete tab[i];
}
delete tab;
}
//funkcja realizujaca tworzenie strumienia wejsciowego, ktory pozwoli wczytac z konsoli wartosci tensora
istream& operator>> (istream &is, Tensor &t){
    double liczba;
    for(int i=0;i<t.dimx;i++){
        for (int j=0; j<t.dimy;j++){
            for (int k=0;k<t.dimz;k++){
                is>>liczba;
                if (is.good()) { //jesli wczytana dana jest lub moze byc przekonwertowana na typ double
                    t.tab[i][j][k]=liczba;
                    t.val=liczba;
                }
                else { //w przeciwnym przypadku blad
                    k--;
                    is.clear();
                    is.sync();
                }
            }
        }
    };
    return is;
}

ostream& operator<< (ostream &os, const Tensor &t){ //drukowanie tensora w konsoli
for (int i=0; i<t.dimx; i++){
    for (int j=0; j<t.dimy; j++){
        for (int k=0; k<t.dimz; k++){
            os<<t.tab[i][j][k]<<" ";
        }
        os<<"\n";
    }
    os<<"-----------\n";
}
return os;
}

Tensor& Tensor::operator=(const Tensor &t){
dimx=t.dimx; dimy=t.dimy; dimz=t.dimz;//pamiec
tab = new double** [dimx];
for (int i=0; i<dimx; i++){
    tab[i]=new double* [dimy];
    for(int j=0; j<dimy; j++){
        tab[i][j]= new double [dimz];
    }
}
for (int i=0; i<dimx; i++){//przepisanie wartosci
    for (int j=0; j<dimy; j++){
        for(int k=0; k<dimz; k++){
            tab[i][j][k]=t.tab[i][j][k];
        }
    }
}
return *this;
}

bool Tensor::operator==(const Tensor &t){
if (!(dimx==t.dimx&&dimy==t.dimy&&dimz==t.dimz)) return false;
for (int i=0; i<dimx; i++){
    for (int j=0; j<dimy; j++){
        for(int k=0; k<dimz; k++){
            if(this->tab[i][j][k]!=t.tab[i][j][k]) return false;
        }
    }
}
return true;
}

bool Tensor::operator!=(const Tensor &t){
if (!(dimx==t.dimx&&dimy==t.dimy&&dimz==t.dimz)) return true;
for (int i=0; i<dimx; i++){
    for (int j=0; j<dimy; j++){
        for(int k=0; k<dimz; k++){
            if(this->tab[i][j][k]!=t.tab[i][j][k]) return true;
        }
    }
}
return false;
}

//tworzenie nowego tensora ktory jest suma dwoch argumentow wejsciowych
Tensor Tensor::operator+(const Tensor& t){
if ((dimx==t.dimx)&&(dimy==t.dimy)&&(dimz==t.dimz)){
    Tensor p(dimx,dimy,dimz);
    for (int i=0; i<dimx; i++){
        for (int j=0; j<dimy; j++){
            for(int k=0; k<dimz; k++){
                p.tab[i][j][k]=tab[i][j][k]+t.tab[i][j][k];
            }
        }
    }
    return p;
}
else cerr<<MESSAGE;
}

Tensor Tensor::operator-(const Tensor& t){
if (dimx==t.dimx&&dimy==t.dimy&&dimz==t.dimz){
    Tensor p(dimx, dimy, dimz);
    for (int i=0; i<dimx; i++){
        for (int j=0; j<dimy; j++){
            for(int k=0; k<dimz; k++){
                p.tab[i][j][k]=val-t.val;
            }
        }
    }
    return p;
}
else cerr<<MESSAGE;
}

Tensor Tensor::operator*(const Tensor &t){
if (dimx==t.dimx&&dimy==t.dimy&&dimz==t.dimz){
    Tensor p(dimx,dimy,dimz);
    for (int i=0; i<dimx; i++){
        for (int j=0; j<dimy; j++){
            for(int k=0; k<dimz; k++){
                p.tab[i][j][k]=val*t.val;
            }
        }
    }
return p;
}
else cerr<<MESSAGE;
}

//modyfikacja wartosci tensora bazowego
void Tensor::operator+=(const Tensor &t){
if (!(dimx==t.dimx&&dimy==t.dimy&&dimz==t.dimz))
    cerr<<MESSAGE;
else{
    for (int i=0; i<dimx; i++){
        for (int j=0; j<dimy; j++){
            for(int k=0; k<dimz; k++){
                this->tab[i][j][k]=val+t.val;
            }
        }
    }

}
}

void Tensor::operator-=(const Tensor &t){
if (!(dimx==t.dimx&&dimy==t.dimy&&dimz==t.dimz))
    cerr<<MESSAGE;
else{
    for (int i=0; i<dimx; i++){
        for (int j=0; j<dimy; j++){
            for(int k=0; k<dimz; k++){
                this->tab[i][j][k]=val-t.val;
            }
        }
    }

}
}

void Tensor::operator*=(const Tensor &t){
if (!(dimx==t.dimx&&dimy==t.dimy&&dimz==t.dimz))
    cerr<<MESSAGE;
else{
    for (int i=0; i<dimx; i++){
        for (int j=0; j<dimy; j++){
            for(int k=0; k<dimz; k++){
                this->tab[i][j][k]=val*t.val;
            }
        }
    }

}
}



//funkcja zmieniajaca wskazana wartosc
void Tensor::change(double w, int a, int b, int c){
    if(a>dimx||b>dimy||c>dimz) cerr<<"No match!"<<endl;
    else tab[a][b][c]=w;
    return;
}


