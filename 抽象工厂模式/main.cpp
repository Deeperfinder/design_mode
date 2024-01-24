#include <iostream>
#include "factory.cpp"
int main(int, char**){
    std::cout << "Hello, from factory!\n";
    Factory *nikeProducer = new NiKeProducer();

    // 耐克生产线产出球鞋
    Shoes *nikeShoes = nikeProducer->CreateShoes();
	// 耐克生产线产出衣服
    Clothes *nikeClothe = nikeProducer->CreateClothe();
    
	// 耐克球鞋广告喊起
    nikeShoes->Show();
	// 耐克衣服广告喊起
    nikeClothe->show();
	
    // 释放资源
    delete nikeShoes;
	delete nikeClothe;
    delete nikeProducer;


    return 0;
}
