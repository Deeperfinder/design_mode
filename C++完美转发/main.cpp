#include <iostream>
#include <utility>
#include <thread>

template<typename Iterator,typename T>
struct accumulate_block
{
  void operator()(Iterator first,Iterator last,T& result)
  {
    result=std::accumulate(first,last,result);
  }
};

template<typename Iterator,typename T>
T parallel_accumulate(Iterator first,Iterator last,T init)
{
  unsigned long const length=std::distance(first,last);

  if(!length) // 1
    return init;

  unsigned long const min_per_thread=25;
  unsigned long const max_threads=
      (length+min_per_thread-1)/min_per_thread; // 2

  unsigned long const hardware_threads=
      std::thread::hardware_concurrency();

  unsigned long const num_threads=  // 3
      std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);

  unsigned long const block_size=length/num_threads; // 4

  std::vector<T> results(num_threads);
  std::vector<std::thread> threads(num_threads-1);  // 5

  Iterator block_start=first;
  for(unsigned long i=0; i < (num_threads-1); ++i)
  {
    Iterator block_end=block_start;
    std::advance(block_end,block_size);  // 6
    threads[i]=std::thread(     // 7
        accumulate_block<Iterator,T>(),
        block_start,block_end,std::ref(results[i]));
    block_start=block_end;  // 8
  }
  accumulate_block<Iterator,T>()(
      block_start,last,results[num_threads-1]); // 9
  std::for_each(threads.begin(),threads.end(),
       std::mem_fn(&std::thread::join));  // 10

  return std::accumulate(results.begin(),results.end(),init); // 11
}






















void an_orther_fun(int a, int& b){
    std::cout << " in an_orther_fun(): a= " << a << ", b = "<< ++b << std::endl; 
}

// 这里需要注意引用折叠规则
/*
1. 当我们将一个左值传递给函数的右值引用参数，且此右值引用参数指向模板类型参数时，编译器推断模板类型参数为实参的左值引用类型。
2. X& &、X& && 和 X&& & 都会折叠为 X&。
3. X&& && 会折叠为 X&&。
*/
template<typename F, typename T1, typename T2>
void transmit(F f, T1&& t1, T2&& t2){
    f(std::forward<T1>(t1), std::forward<T2>(t2));
}

int main()
{
    int a = 2, b = 3;
    std::cout << " before transmit(): a = "<< a << ", b = " << b << std::endl;
    transmit(an_orther_fun, a, b);
    std::cout << " after transmit(): a = "<< a << ", b = " << b << std::endl;


    float i = 3.1415926;
    int d = static_cast<int>(i); // 转换为int类型
    std::cout << "d: " << d <<std::endl;

    std::cout << std::thread::hardware_concurrency() << std::endl;
    return 0;
}