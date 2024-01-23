#include <iostream>


// 鞋子抽象类
class Shoes
{
public:
    virtual ~Shoes() {}
    virtual void Show(){
        std::cout<< " Shoes！！！" << std::endl;
    } ;
};

// 耐克鞋子
class NiKeShoes : public Shoes
{
public:
    void Show()
    {
        std::cout << "我是耐克球鞋，我的广告语：Just do it" << std::endl;
    }
};

// 阿迪达斯鞋子
class AdidasShoes : public Shoes
{
public:
    void Show()
    {
        std::cout << "我是阿迪达斯球鞋，我的广告语:Impossible is nothing" << std::endl;
    }
};

// 李宁鞋子
class LiNingShoes : public Shoes
{
public:
    void Show()
    {
        std::cout << "我是李宁球鞋，我的广告语：Everything is possible" << std::endl;
    }
};


enum SHOES_TYPE{
    NIKE,
    LININGS,
    ADIDAS
};

class ShoesFactory
{
    public:
        virtual Shoes *CreateShoes() = 0;
        virtual ~ShoesFactory(){};
};

// nike生产者
class NikeProducer : public ShoesFactory{
    public:
        Shoes *CreateShoes(){
            return new NiKeShoes();
        }
};

// adidas 生产者
class AdidasProducer : public ShoesFactory{
    public:
        Shoes *CreateShoes(){
            return new AdidasShoes();
        }
};

// 李宁生产者/生产链
class LiNingProducer : public ShoesFactory
{
public:
    Shoes *CreateShoes()
    {
        return new LiNingShoes();
    }
};