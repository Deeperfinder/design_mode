#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int main()
{
    std::chrono::steady_clock::time_point t1, t2;
    double dt;
    int n = 10000000;

    vector<int> vec1, vec2;

    t1 = std::chrono::steady_clock::now();

    for(int i=0; i<n; i++)
        vec1.emplace_back(i);

    t2 = std::chrono::steady_clock::now();
    dt = std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1).count();

    cout << "vec1.size: " << vec1.size() << endl;
    cout << "vec1.capacity: " << vec1.capacity() << endl;
    cout << "No reserve time: " << dt << endl << endl;

    t1 = std::chrono::steady_clock::now();
    vec2.reserve(n);

    for(int i=0; i<n; i++)
        vec2.emplace_back(i);

    t2 = std::chrono::steady_clock::now();
    dt = std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1).count();

    cout << "vec2.size: " << vec2.size() << endl;
    cout << "vec2.capacity: " << vec2.capacity() << endl;
    cout << "Use reserve time: " << dt << endl;

    return 0;
}