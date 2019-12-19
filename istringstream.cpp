#include <iostream>
#include <chrono>
#include <vector>
#include <sstream>

int main(int argc, char * argv[])
{
    std::cout << "========== istringstream ==========" << std::endl;
    int res = 0;
    std::vector<int> n;
    std::istringstream iss(argv);
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < str.size(); ++i)
    {
        iss >> res;
        n.push_back(res);
    }
    std::cout << "Execution time: " << static_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - start).count() << std::endl;
    for (int i = 0; i < n.size(); ++i) std::cout << n[i] << std::endl;
    return 0;
}
