#include <iostream>
#include <vector>
#include <numeric>
 
// Helper function to 3–partition problem.
// It returns true if there exist three subsets with a given sum
bool isSubsetExist(std::vector<int> const &S, int n, int a, int b, int c, std::vector<int> &arr)
{
    if (a == 0 && b == 0 && c == 0) {
        return true;
    }
 
    if (n < 0) {
        return false;
    }
 
    bool A = false;
    if (a - S[n] >= 0)
    {
        arr[n] = 1; 
        A = isSubsetExist(S, n - 1, a - S[n], b, c, arr);
    }
 
    bool B = false;
    if (!A && (b - S[n] >= 0))
    {
        arr[n] = 2;        B = isSubsetExist(S, n - 1, a, b - S[n], c, arr);
    }
 
    bool C = false;
    if ((!A && !B) && (c - S[n] >= 0))
    {
        arr[n] = 3;        C = isSubsetExist(S, n - 1, a, b, c - S[n], arr);
    }
 
    return A || B || C;
}
 
void partition(std::vector<int> const &S)
{
    int sum = accumulate(S.begin(), S.end(), 0);
 
    int n = S.size();
 
    std::vector<int> arr(n);
 
    bool result = (n >= 3) && !(sum % 3) &&
            isSubsetExist(S, n - 1, sum/3, sum/3, sum/3, arr);
 
    if (!result)
    {
        std::cout << "3-Partition of set is not possible";
        return;
    }
 
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Partition " << i << " is ";
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i + 1) {
                std::cout << S[j] << " ";
            }
        }
        std::cout << "\n";
    }
}
 
int main()
{

    int n;
    std::cin >> n;

    std::vector<int> S(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> S[i];
    }
 
    partition(S);
 
    return 0;
}