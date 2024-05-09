#include <iostream>
#include <vector>
#include <utility>

// target function. left value version
void target(int& value){
    std::cout<<"target(int& value) left value version called with value="<<value<<std::endl;
}

void target(int&& value){
    std::cout<<"target(int&& value) rvalue version called with value="<<value<<std::endl;
}


template<typename T>
// 万能引用版本，可以接受左值和右值 T&& arg
void f(T&& arg){        
    // 使用std::forward将参数转发给target函数
    target(std::forward<T>(arg));
}


int main() {

int x = 10;
f(x); // calls f<int&>(x)
f(20); // calls f<int&&>(20)

}
