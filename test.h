#ifndef TEST_H
#define TEST_H
class test{
public:
friend Tensor;
    void wymiary(int a, int b, int c);
    void wczytanie(Tensor &t1);
    bool test1(Tensor &t1, Tensor &t2, const Tensor &wynik);
    bool test2(Tensor &t1, Tensor &t2, const Tensor &wynik);
    bool test3(Tensor &t1, Tensor &t2, const Tensor &wynik);
    bool test4(Tensor &t1, Tensor &t2, const Tensor &wynik);
    bool test5(Tensor &t1, Tensor &t2, const Tensor &wynik);
    bool test6(Tensor &t1, Tensor &t2, const Tensor &wynik);
};
#endif

