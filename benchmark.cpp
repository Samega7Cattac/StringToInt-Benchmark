#include <iostream>
#include <chrono>
#include <vector>
#include <charconv>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <random>

#define N_TIMES 10000000

void test_from_chars(char * start, char * end, int * res);
void test_atoi(char * str, int * res);
void test_stoi(std::string str, int * res);
void test_istringstream(std::istringstream * str, int * res);
void test_strtol(char * str, int * res);
void test_own(char *, int * res);

int main(int argc, char * argv[])
{
    int n_times = N_TIMES;
    if (argc > 1) n_times = atoi(argv[1]);
    double sum_from_chars = 0;
    double sum_atoi = 0;
    double sum_stoi = 0;
    double sum_istringstream = 0;
    double sum_strtol = 0;
    double sum_own = 0;
    int res = 0;
    std::vector<char *> str;
    for (int i = 0; i < n_times; ++i) str.push_back((char *)std::to_string(rand()).c_str());
    for(int i = 0; i < n_times; ++i)
    {
        char * end = str[i] + strlen(str[i]);
        auto start = std::chrono::high_resolution_clock::now();
        test_from_chars(str[i], end, &res);
        sum_from_chars += std::chrono::duration<double, std::nano>(std::chrono::high_resolution_clock::now() - start).count();
    }
    for(int i = 0; i < n_times; ++i)
    {
        auto start = std::chrono::high_resolution_clock::now();
        test_atoi(str[i], &res);
        sum_atoi += std::chrono::duration<double, std::nano>(std::chrono::high_resolution_clock::now() - start).count();
    }
    for(int i = 0; i < n_times; ++i)
    {
        std::string n(str[i]);
        auto start = std::chrono::high_resolution_clock::now();
        test_stoi(n, &res);
        sum_stoi += std::chrono::duration<double, std::nano>(std::chrono::high_resolution_clock::now() - start).count();
    }
    for(int i = 0; i < n_times; ++i)
    {
        std::istringstream iss(str[i]);
        auto start = std::chrono::high_resolution_clock::now();
        test_istringstream(&iss, &res);
        sum_istringstream += std::chrono::duration<double, std::nano>(std::chrono::high_resolution_clock::now() - start).count();
    }
    for(int i = 0; i < n_times; ++i)
    {
        auto start = std::chrono::high_resolution_clock::now();
        test_strtol(str[i], &res);
        sum_strtol += std::chrono::duration<double, std::nano>(std::chrono::high_resolution_clock::now() - start).count();
    }
    for(int i = 0; i < n_times; ++i)
    {
        auto start = std::chrono::high_resolution_clock::now();
        test_own(str[i], &res);
        sum_own += std::chrono::duration<double, std::nano>(std::chrono::high_resolution_clock::now() - start).count();
    }
    std::cout << std::fixed;
    std::cout << "from_chars: " << sum_from_chars / n_times << " nanosec" << std::endl;
    std::cout << "atoi: " << sum_atoi / n_times << " nanosec" << std::endl;
    std::cout << "stoi: " << sum_stoi / n_times << " nanosec" << std::endl;
    std::cout << "istringstream: " << sum_istringstream / n_times << " nanosec" << std::endl;
    std::cout << "strtol: " << sum_strtol / n_times << " nanosec" << std::endl;
    std::cout << "own: " << sum_own / n_times << " nanosec" << std::endl;
    return 0;
}

void test_from_chars(char * start, char * end, int * res)
{
    std::from_chars(start, end, *res);
}

void test_atoi(char * str, int * res)
{
    *res = atoi(str);
}

void test_stoi(std::string str, int * res)
{
    *res = std::stoi(str, nullptr);
}

void test_istringstream(std::istringstream * str, int * res)
{
    *str >> *res;
}

void test_strtol(char * str, int * res)
{
    *res = strtol(str, &str, 10);
}

void test_own(char * str, int * res)
{
    while(*str) {
        *res = (*res << 1) + (*res << 3) + *(str++) - 48;
    }
}
