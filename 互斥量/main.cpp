#include <iostream>
#include <mutex>
#include <algorithm>
#include <list>
#include <vector>
#include <memory>

std::list<int> some_list;
std::mutex some_mutex;

void add_to_list(int new_value){
    std::lock_guard<std::mutex> guard(some_mutex);
    some_list.push_back(new_value);
}

bool list_contains(int value_to_find){
    std::lock_guard<std::mutex> guard(some_mutex);
    return std::find(some_list.begin(), some_list.end(), value_to_find) != some_list.end();
}

struct inferdata{
    int value;
    int count;
};
using InferDataPtr = std::shared_ptr<inferdata>;
using BatchData = std::vector<InferDataPtr>;

struct package{
    BatchData data;

    std::string tag;
    static std::shared_ptr<package> Create(uint32_t data_num, const std::string &tag="") noexcept{
        auto ret = std::make_shared<package>();
        ret->data.reserve(data_num);
        for (uint32_t idx = 0; idx < data_num; ++idx)
        {
            ret->data.emplace_back(std::shared_ptr<InferDataPtr>(new InferDataPtr));
        }
        ret->tag = tag;
        return ret;
    }

};







int main(int, char**){
    std::cout << "Hello, from app!\n";

    std::vector<int> values;
    values.push_back(1);

}
