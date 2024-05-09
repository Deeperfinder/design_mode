#include <iostream>
#include <mutex>
#include <thread>

std::once_flag flag;
void do_once() {
    std::call_once(flag, []() {
        std::cout << "只执行一次" << std::endl;
    });
}

int main() {
    std::thread t1(do_once);
    std::thread t2(do_once);
    std::thread t3(do_once);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}

/*
在上面的代码中，函数 do_once 会被三个不同的线程调用，但是其中的 lambda 函数（[]() { std::cout << "只执行一次" << std::endl; }）将保证只执行一次，
无论有多少线程调用 do_once 函数。这是因为 std::call_once 会检查传入的 std::once_flag（在这个例子中是名为 flag 的变量），
如果标志未被设置，它将执行给定的函数，并将标志设置为已调用状态。如果标志已经被设置，std::call_once 将不会执行该函数。
这种机制非常适合于需要延迟初始化的全局或静态对象，尤其是在多线程环境中，它可以保证线程安全且高效地初始化。
*/