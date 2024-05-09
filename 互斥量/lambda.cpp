#include <iostream>
#include <memory>  // std::make_unique
#include <utility> // std::move

// 表达式捕获
void lambda_expression_capture() {
    auto important = std::make_unique<int>(1);
    auto add = [v1 = 1, v2 = std::move(important)](int x, int y) -> int {
    return x+y+v1+(*v2);
};
std::cout << add(3,4) << std::endl;
}

// 在上面的代码中，important 是一个独占指针，是不能够被 “=” 值捕获到，这时候我们可以将其转
// 移为右值，在表达式中初始化。

// 泛型lambda
auto add = [](auto x, auto y) {
    return x+y;
};
int main(){
    add(1, 2);
    add(1.1, 2.2);
}