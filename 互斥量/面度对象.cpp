// 面度对象
#include <iostream>
#include <memory>

// 委托构造
//C++11 引入了委托构造的概念，这使得构造函数可以在同一个类中一个构造函数调用另一个构造函
//数，从而达到简化代码的目的：
class Base{
    public:
        int value1;
        int value2;
        Base(){
            value1 = 1;
        }
        Base(int value):Base(){
            value2 = value;        
        }
        virtual void foo(){
            std::cout << "Base::foo()" << std::endl;
        }
};
// 继承构造
//在传统 C++ 中，构造函数如果需要继承是需要将参数一一传递的，这将导致效率低下。C++11 利
//用关键字 using 引入了继承构造函数的概念：
class Subclass : public Base{
    public:
        using Base::Base; // 继承构造

        void foo() override{
            std::cout << "Subclass::foo()" << std::endl;
        }
};

// 显示虚函数重载
// C++11 引入了 override 和 final 这两个关键字来防止上述情形的发生。
// final 则是为了防止类被继续继承以及终止虚函数继续重载引入的。

// struct Base {
//     virtual void foo() final;
// };
// struct SubClass1 final: Base {
// }; // 合法
// struct SubClass2 : SubClass1 {
// }; // 非法, SubClass1 已 final
// struct SubClass3: Base {
//     void foo(); // 非法, foo 已 final
// };

// 显示禁用默认函数
class Magic{
    public:
        Magic() = default;
        Magic& operator=(const Magic&) = delete; // 禁止拷贝构造函数
        Magic(int magic_number);
};
int main(){
    Base b(2);
    std::cout << b.value1 << " " << b.value2 << std::endl;
    std::shared_ptr<Base> sp(new Base(3));
    sp->foo();


}