#include <iostream>
#include "tensor.h"
#include <cstdio>
#include "test.h"

using namespace std;

bool test::test1(Tensor &t1,Tensor &t2, const Tensor &wynik){

Tensor t3;
t3=t2+t1;
if (t3==wynik) return true;
else false;
}

bool test::test2(Tensor &t1,Tensor &t2, const Tensor &wynik){

Tensor t3;
t3=t2-t1;
if (t3==wynik) return true;
else false;
}

bool test::test3(Tensor &t1,Tensor &t2, const Tensor &wynik){
Tensor t3;
t3=t2*t1;
if (t3==wynik) return true;
else false;
}

bool test::test4(Tensor &t1, Tensor &t2, const Tensor &wynik){

t1+=t2;
if(t1==wynik) return true;
else false;
}

bool test::test5(Tensor &t1, Tensor &t2, const Tensor &wynik){
t1-=t2;
if(t1==wynik) return true;
else false;
}

bool test::test6(Tensor &t1, Tensor &t2, const Tensor &wynik){
t1*=t2;
if(t1==wynik) return true;
else false;
}

void test::wymiary(int a, int b, int c){
Tensor t=Tensor(a,b,c);
cout<<"Tensor podstawowy o podanych wymiarach to:\n"<<t;
}

void test::wczytanie(Tensor &t1){
cin>>t1;
cout<<"Wczytany tesnor to:\n"<<t1;
}

