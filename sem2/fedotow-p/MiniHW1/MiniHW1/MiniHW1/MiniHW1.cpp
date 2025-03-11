#include <iostream>
#include "Functions.h"

int main()
{
    std::vector<float> numbers = { 42, 69, 420, 1488, 228, 666, 777, 1337, 2007, 2025 };

    std::cout << "Average arithmetic value: " << averageArithmeticValue(numbers) << std::endl;
    std::cout << "Median: " << median(numbers) << std::endl;
    std::cout << "Average square value: " << averageSquareValue(numbers) << std::endl;
    std::cout << "Variance: " << variance(numbers) << std::endl;
}