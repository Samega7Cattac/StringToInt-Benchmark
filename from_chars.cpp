#include <iostream>
#include <chrono>
#include <vector>
#include <charconv>

int main(int argc, char * argv[])
{
    std::cout << "========== from_chars ==========" << std::endl;
    int res = 0;
    std::vector<std::string> str;
    std::vector<int> n;
    for (int i = 1; i < argc; ++i) str.push_back(argv[1]);
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < str.size(); ++i)
    {
        std::from_chars(str.at(i).data(), str.at(i).data() + str.at(i).length(), res);
        n.push_back(res);
    }
    std::cout << "Execution time: " << static_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - start).count() << std::endl;
    for (int i = 0; i < n.size(); ++i) std::cout << n[i] << std::endl;
    return 0;
}
