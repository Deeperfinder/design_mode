#include<iostream>

class Clothes
{
    public:
        virtual void show()=0;
        virtual ~Clothes(){}
};

class NikeClothe : public Clothes
{
    public:
        void show(){
            std::cout << "我是耐克衣服，时尚我最在行！" << std::endl;
        }
};

// 基类 鞋子
class Shoes
{
public:
    virtual void Show() = 0;
    virtual ~Shoes() {}
};

// 耐克鞋子
class NiKeShoes : public Shoes
{
public:
    void Show()
    {
        std::cout << "我是耐克球鞋，让你酷起来！" << std::endl;
    }
};

// 总厂
class Factory{
    public:
        virtual Shoes * CreateShoes()=0;
	    virtual Clothes *CreateClothe() = 0;
        virtual ~Factory() {}
};

// 耐克生产者/生产链
class NiKeProducer : public Factory
{
public:
    Shoes *CreateShoes()
    {
        return new NiKeShoes();
    }
	
	Clothes *CreateClothe()
    {
        return new NikeClothe();
    }
};