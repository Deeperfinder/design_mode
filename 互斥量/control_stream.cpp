/*
* constexpr 关键字，它将表达式或函数编译为常量结果。
*/

#include <iostream>
// 类型别名模板
template<typename T0>
void printf1(T0 value){
    std::cout << "single value:" << value << std::endl;
}

template<typename T, typename... Ts>
void printf1(T value, Ts... args){
    std::cout << "value: " << value << std::endl;  
    printf1(args...);
}

// 变参模板展开
template<typename T0, typename... T>
void printf2(T0 t0, T... t){
    std::cout << "t0: " << t0 << std::endl;
    if constexpr(sizeof...(t) > 0) printf2(t...);
}

// 初始化列表展开
template<typename T, typename... Ts>
auto printf3(T value, Ts... args){
    std::cout << "value: " << value << std::endl;
    (void)std::initializer_list<T>{([args]{
        std::cout << "args: " << args << std::endl;
    }(), value)...};
}

// 折叠表达式
template<typename ...T>
auto sum(T... t){
    return (t + ...);
}

// 非类型模板参数推到
template <typename T, typename U>
auto add(T t, U u){
    return t + u;
}

// 编译器辅助完成具体类型的推到
template <auto value> void foo(){
    std::cout << "value:" << value << std::endl;
    return;
}
int main(){
    // printf1(1, 2, 3, 4, 5);
    printf2(6, 7, 8, 9, 10);
    // printf3(11, 12, 13, 14, 15);
    std::cout<< "sum: " << sum(1.2, 1.3, 1.4, 1.5, 8.8, 6.2) << std::endl;
    foo<10>();
    return 0;

}