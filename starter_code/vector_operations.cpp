
#include <iostream>
#include <vector>
#include <random>
#include <chrono>

// Fill the vector with random floating point values
void fill_vector(std::vector<float>& v)
{
    for(int i=0;i<v.size();i++){
       v[i]=static_cast<float>(rand()) / RAND_MAX;
    }
}

// Multiply each element by a constant

void scale_vector(std::vector<float>& v, float scale)
{
    
    for(int i=0;i<v.size();i++){

     v[i]=v[i]*scale;
}
}

// Compute the sum of all elements
float sum_vector(const std::vector<float>& v)
{
   
    float sum = 0.0f;
   #pragma omp parallel for reduction(+ : sum)


    for(int i=0;i<v.size();i++)
{
   sum=sum+v[i];
}
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
