#include <iostream>
#include "factory.h"
int main(int, char**){
    std::cout << "Hello, from factory_test!\n";

    // ================ 生产耐克流程 ==================== //
    // 鞋厂开设耐克生产线
    ShoesFactory *niKeProducer = new NikeProducer();
    // 耐克生产线产出球鞋
    Shoes *nikeShoes = niKeProducer->CreateShoes();
    // 耐克球鞋广告喊起
    nikeShoes->Show();
    // 释放资源
    delete nikeShoes;
    delete niKeProducer;

    // ================ 生产阿迪达斯流程 ==================== //
    // 鞋厂开设阿迪达斯生产者
    ShoesFactory *adidasProducer = new AdidasProducer();
    // 阿迪达斯生产线产出球鞋
    Shoes *adidasShoes = adidasProducer->CreateShoes();
    // 阿迪达斯球鞋广喊起
    adidasShoes->Show();
    // 释放资源
    delete adidasShoes;
    delete adidasProducer;

    return 0;
}
