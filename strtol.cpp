#include <iostream>
#include <chrono>
#include <vector>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    std::cout << "========== strtol ==========" << std::endl;
    std::vector<char *> str;
    std::vector<long int> n;
    for (int i = 1; i < argc; ++i) str.push_back(argv[1]);
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < str.size(); ++i)
    {
        n.push_back(strtol(str[i], &str[i], 10));
    }
    std::cout << "Execution time: " << static_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - start).count() << std::endl;
    for (int i = 0; i < n.size(); ++i) std::cout << n[i] << std::endl;
    return 0;
}
