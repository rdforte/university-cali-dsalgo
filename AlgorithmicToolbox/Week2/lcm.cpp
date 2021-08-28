#include <iostream>

long long lcm(long long a, long long b)
{
  long long multipleA = a;
  long long multipleB = b;

  while (multipleB % a != 0 || multipleA % b != 0)
  {
    if (multipleB % a != 0)
      multipleB += b;
    if (multipleA % b != 0)
      multipleA += a;
  }

  return multipleA;
}

int main()
{
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
