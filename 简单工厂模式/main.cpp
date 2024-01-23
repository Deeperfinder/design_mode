#include <iostream>
#include "simple_factory.h"

int main(int, char**){
    
/*这行代码也创建了一个 LiNingShoes 对象，但是这次 lingning1 是一个指向 Shoes 基类的指针。
尽管 lingning1 实际上指向的是一个 LiNingShoes 对象，但它被声明为指向 Shoes 类型的指针。
这种赋值是合法的，并且是多态的一种表现。
当您通过基类指针调用虚函数时，将会根据对象的实际类型来调用相应的函数。
这允许您在不知道对象具体类型的情况下，通过基类接口来处理不同类型的派生类对象。*/
    LiNingShoes *lining = new LiNingShoes();
    Shoes *lingning1 = new LiNingShoes();

    // 构造工厂对象
    ShoesFactory shoesFactory;

    // 从鞋工厂对象创建阿迪达斯鞋对象
    Shoes *pNikeShoes = shoesFactory.CreateShoes(NIKE);
    if (pNikeShoes != NULL)
    {
        // 耐克球鞋广告喊起
        pNikeShoes->Show();

        // 释放资源
        delete pNikeShoes;
        pNikeShoes = NULL;
    }
     // 从鞋工厂对象创建阿迪达斯鞋对象
    Shoes *pLiNingShoes = shoesFactory.CreateShoes(LININGS);
    if (pLiNingShoes != NULL)
    {
        // 李宁球鞋广告喊起
        pLiNingShoes->Show();

        // 释放资源
        delete pLiNingShoes;
        pLiNingShoes = NULL;
    }

    // 从鞋工厂对象创建阿迪达斯鞋对象
    Shoes *pAdidasShoes = shoesFactory.CreateShoes(ADIDAS);
    if (pAdidasShoes != NULL)
    {
        // 阿迪达斯球鞋广告喊起
        pAdidasShoes->Show();

        // 释放资源
        delete pAdidasShoes;
        pAdidasShoes = NULL;
    }


}
