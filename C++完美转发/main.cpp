#include <iostream>
#include <utility>

void an_orther_fun(int a, int& b){
    std::cout << " in an_orther_fun(): a= " << a << ", b = "<< ++b << std::endl; 
}

// 这里需要注意引用折叠规则
/*
1. 当我们将一个左值传递给函数的右值引用参数，且此右值引用参数指向模板类型参数时，编译器推断模板类型参数为实参的左值引用类型。
2. X& &、X& && 和 X&& & 都会折叠为 X&。
3. X&& && 会折叠为 X&&。
*/
template<typename F, typename T1, typename T2>
void transmit(F f, T1&& t1, T2&& t2){
    f(std::forward<T1>(t1), std::forward<T2>(t2));
}

int main()
{
    int a = 2, b = 3;
    std::cout << " before transmit(): a = "<< a << ", b = " << b << std::endl;
    transmit(an_orther_fun, a, b);
    std::cout << " after transmit(): a = "<< a << ", b = " << b << std::endl;


    float i = 3.1415926;
    int d = static_cast<int>(i); // 转换为int类型
    std::cout << "d: " << d <<std::endl;
    return 0;
}