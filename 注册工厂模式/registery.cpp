#include <memory>
#include <iostream>
#include <string>
#include <map>
#include <functional>

/*
* 在程序运行时候动态创建对象，同时不需要在工厂类中显式的引用具体类。
*
* 把产品注册的对象用std::map的方式保存，通过key-valve的方式可以轻松简单的获取对应的产品对象实例。
*
*/
class Product {
    public:
        virtual void use() = 0;
        virtual ~Product(){};
};

class concrete_product1 : public Product {
    public:
        void use() override {
            std::cout << "Using concreteProduct1" << std::endl;
        }
};

class concrete_product2 : public Product {
    public:
        void use() override {
            std::cout << "Using concreteProduct2" << std::endl;
        }
};

// 实现工厂类，工厂类将使用一个映射从字符串ID到创建函数的映射来存储具体产品的构造函数
class Factory{
    private:
        std::map<std::string, std::function<Product*()>> registry;

    public:
        void Register(const std::string& name, std::function<Product*()> constructor){
            registry[name] = constructor;
        };

        Product* create(const std::string& name){
            auto it = registry.find(name);
            if(it != registry.end()){
                return it->second();
            }
            return nullptr;
        }
};

int main(){
    Factory factory;
    factory.Register("ConcreteProduct1", []()-> Product* { return new concrete_product1();});
    factory.Register("ConcreteProduct2", []()-> Product* { return new concrete_product2();});

    // create product
    Product* productA = factory.create("ConcreteProduct1");
    if (productA != nullptr){
        productA->use();
        delete productA;
    }

    Product* productB = factory.create("ConcreteProduct2");
    if (productB != nullptr){
        productB->use();
        delete productB;
    }

    return 0;

}