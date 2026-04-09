#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;
// Fill the vector with random floating point values
void fill_vector(std::vector<float>& v)
{

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(0.0f,1.0f);// TODO: initialize a random number generator
    for(size_t i = 0;i<v.size();++i){ // TODO: fill the vector with random values
        v[i] = dis(gen);
    }
    
}

// Multiply each element by a constant
void scale_vector(std::vector<float>& v, float scale)
{
    for(float& val:v){
        val *= scale;
    }
}

// Compute the sum of all elements
float sum_vector(const std::vector<float>& v)
{
    float sum = 0.0f;

    
    for (float val : v) {
        sum += val;
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