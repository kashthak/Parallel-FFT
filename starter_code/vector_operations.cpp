#include <iostream>
#include <vector>
#include <random>
#include <chrono>
// Fill the vector with random floating point values
void fill_vector(std::vector<float>& v)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    int n= v.size();
    for(int i=0;i<n; i++){
        v[i]=(float)mt();
    }
}

// Multiply each element by a constant
void scale_vector(std::vector<float>& v, float scale)
{
    int n=v.size();
    for(int i=0;i<n;i++){
    v[i] = v[i] * scale;
    // TODO: loop through the vector and scale each element
    }
}

// Compute the sum of all elements
float sum_vector(const std::vector<float>& v)
{
    float sum = 0.0f;
    int n = v.size();
    for(int i =0; i<n;i++){
        sum+=v[i];
    }
    // TODO: compute sum of all elements

    return sum;
}

int main()
{
    const size_t N = 10000000; // 10 million elements

    std::vector<float> data(N);

    auto start = std::chrono::high_resolution_clock::now();

    fill_vector(data);

    scale_vector(data, 2.0f);

    float result = sum_vector(data);

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> runtime = end - start;

    std::cout << "Vector size: " << N << std::endl;
    std::cout << "Sum: " << result << std::endl;
    std::cout << "Runtime: " << runtime.count() << " seconds\n";

    return 0;
}