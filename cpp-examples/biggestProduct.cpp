#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;

  float *numbers = new float[n];

  for (int i = 0; i < n; i++)
  {
    cin >> numbers[i];
  }

  sort(numbers, numbers + n);

  float biggestProduct = numbers[n - 1] * numbers[n - 2];
  float smallestProduct = numbers[0] * numbers[1];
  float res = biggestProduct;

  if (smallestProduct > biggestProduct)
    res = smallestProduct;

  if (res == -0)
    res = 0;
  cout << res << endl;
}