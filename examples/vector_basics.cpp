#include <iostream>
#include <vector>

int main()
{
    std::vector<float> data(5);

    // Initialize values
    for (int i = 0; i < data.size(); i++)
    {
        data[i] = i * 1.5f;
    }

    // Print values
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}