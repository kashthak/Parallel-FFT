#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>
#define NUM_THREADS X
// BAD version (false sharing)
void run_bad(int num_threads)
{
    std::vector<float> partial_sums(num_threads, 0.0f);

    auto start = std::chrono::high_resolution_clock::now();

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();

        for (int i = 0; i < 100000000; i++)
        {
            partial_sums[tid] += 1.0f;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> runtime = end - start;

    std::cout << "False Sharing (BAD): " << runtime.count() << " seconds\n";
}

// GOOD version (fixed)
struct Padded
{
    float value;
    char padding[64];
};

void run_good(int num_threads)
{
    std::vector<Padded> partial_sums(num_threads);

    auto start = std::chrono::high_resolution_clock::now();

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();

        for (int i = 0; i < 100000000; i++)
        {
            partial_sums[tid].value += 1.0f;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> runtime = end - start;

    std::cout << "False Sharing (FIXED): " << runtime.count() << " seconds\n";
}

int main()
{
    int num_threads = omp_get_max_threads();

    std::cout << "Threads: " << num_threads << "\n";

    run_bad(num_threads);
    run_good(num_threads);

    return 0;
}