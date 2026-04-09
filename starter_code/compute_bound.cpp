#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>

int main()
{
    const size_t N = 10000000;

    std::vector<float> data(N, 1.0f);

    auto start = std::chrono::high_resolution_clock::now();

    // Compute-heavy operation
    #pragma omp parallel for
    for (size_t i = 0; i < N; i++)
    {
        float x = data[i];

        for (int j = 0; j < 100; j++)
        {
            x = x * x + 1.0f;
        }

        data[i] = x;
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> runtime = end - start;

    std::cout << "Threads: " << omp_get_max_threads() << std::endl;
    std::cout << "Compute-bound runtime: " << runtime.count() << " seconds\n";

    return 0;
}