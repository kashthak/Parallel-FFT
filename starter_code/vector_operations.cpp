#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <omp.h>

// Fill the vector with random values
void fill_vector(std::vector<float>& v)
{
    std::mt19937 gen(42);
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);

    for (size_t i = 0; i < v.size(); i++)
    {
        v[i] = dist(gen);
    }
}

// Multiply each element by a constant
void scale_vector(std::vector<float>& v, float scale)
{
    // Parallelize this loop using OpenMP
    #pragma omp parallel for
    for (size_t i = 0; i < v.size(); i++)
    {
        v[i] *= scale;
    }
}

// Compute the sum of all elements
float sum_vector(const std::vector<float>& v)
{
    float sum = 0.0f;
    // Parallelize using reduction to avoid race conditions
    #pragma omp parallel for reduction(+ : sum)
    for (size_t i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }

    return sum;
}

int main()
{
    const size_t N = 10000000;

    std::vector<float> data(N);

    auto start = std::chrono::high_resolution_clock::now();

    fill_vector(data);
    scale_vector(data, 2.0f);
    float result = sum_vector(data);

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> runtime = end - start;

    std::cout << "Threads: " << omp_get_max_threads() << std::endl;
    std::cout << "Vector size: " << N << std::endl;
    std::cout << "Sum: " << result << std::endl;
    std::cout << "Runtime: " << runtime.count() << " seconds\n";

    return 0;
}