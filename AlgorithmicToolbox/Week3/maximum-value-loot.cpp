#include <iostream>
#include <algorithm>
#include <array>

class WeightedValue
{
    float weight;
    float value;

public:
    WeightedValue(float v, float w)
    {
        weight = w;
        value = v;
    }

public:
    float getValuePerKG()
    {
        return value / weight;
    }
};

bool sortByHeighestValue(WeightedValue a, WeightedValue b)
{
    return a.getValuePerKG() > b.getValuePerKG();
}

int main()
{
    std::array<WeightedValue, 3> arr = {WeightedValue(60, 20), WeightedValue(100, 50), WeightedValue(120, 30)};
    std::sort(arr.begin(), arr.end(), sortByHeighestValue);
    std::cout << arr[0].getValuePerKG() << "\n"
              << arr[1].getValuePerKG() << "\n"
              << arr[2].getValuePerKG();

    return 0;
}