#include <iostream>
#include <vector>
#include <initializer_list>
#include <tuple>
#include <string>
// 初始化列表
class MagicFoo{
public:
    std::vector<int> vec;
    MagicFoo(std::initializer_list<int> list){
        for(std::initializer_list<int>::iterator it = list.begin(); 
                it!=list.end(); it++)
            vec.push_back(*it);
    }
};
class Foo{
public:   
    int value_a;
    int value_b;
    Foo(int a, int b) : value_a(a), value_b(b){}
};

// 结构化绑定
std::tuple<int, double, std::string> f() {
    return std::make_tuple(1, 3.14, "hello");
} 

int add(auto x, auto y){
    return x+y;
}
// 尾返回类型（trailing return type）
template<typename T, typename U>
auto add2(T x, U y) -> decltype(x+y){
    return x+y;
}

template<typename T, typename U>
auto add3(T x, U y){
    return x+y;
}
// decltype 推断表达式的类型


// decltype(auto) 是 C++14 开始提供的一个略微复杂的用法。
std::string lookup1();
std::string& lookup2();
// 在 C++11 中，封装实现是如下形式：
// std::string look_up_a_string_1() {
//     return lookup1();
// }
// std::string& look_up_a_string_2() {
//     return lookup2();
// }
// 而有了 decltype(auto)，我们可以让编译器完成这一件烦人的参数转发：
decltype(auto) look_up_a_string_1() {
    return lookup1();
}
decltype(auto) look_up_a_string_2() {
    return lookup2();
}

int main(){
    int arr[3] = {1,2,3};
    Foo foo(1,2);
    std::vector<int> vec = {1,2,3};

    for (std::vector<int>::iterator it = vec.begin(); it!=vec.end(); it++){
        std::cout << *it << std::endl;
    }

    MagicFoo magicFoo = {1,2,3,4,5}; 
    std::cout<< "magicFoo: ";
    for(std::vector<int>::iterator it = magicFoo.vec.begin(); 
        it!=magicFoo.vec.end(); it++)
        std::cout<< *it << std::endl;
    // 结构化绑定
    auto [x, y, z] = f();
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "z: " << z << std::endl;

    auto j = 5;
    auto i = 6;
    std::cout << "add(j, i): " << add(j, i) << std::endl;
    
    if (std::is_same<decltype(x), int>::value)
    std::cout << "type x == int" << std::endl;
    if (std::is_same<decltype(x), float>::value)
    std::cout << "type x == float" << std::endl;
    if (std::is_same<decltype(x), decltype(z)>::value)
    std::cout << "type z == type x" << std::endl;


    return 0;
}

