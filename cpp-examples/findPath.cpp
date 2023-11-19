#include <iostream>

using namespace std;

int findShortestPathValue(int** matrix, int n, int m, int i, int j)
{
  int shortestPathValue = matrix[i][j];
  if(i == n - 1 && j < m - 1) // no more down paths
    shortestPathValue += findShortestPathValue(matrix, n, m, i, j + 1);
  else if(j == m - 1 && i < n - 1) // no more right paths
    shortestPathValue += findShortestPathValue(matrix, n, m, i + 1, j);
  else if(i == n - 1 && j == m - 1) // reached bottom right corner
    shortestPathValue += 0;
  else  // there are both right and down paths
  {
    int rightPathValue = findShortestPathValue(matrix, n, m, i, j + 1);
    int downPathValue = findShortestPathValue(matrix, n, m, i + 1, j);

    if (rightPathValue < downPathValue)
      shortestPathValue += rightPathValue;
    else
      shortestPathValue += downPathValue;
  }

  // cout << "(" << i << ", " << j << ") = " << shortestPathValue << endl;
  return shortestPathValue;
}

int main()
{
  int n, m;
  cin >> n >> m;

  // initialize 2D array
  int** matrix = new int*[n];
  for(int i = 0; i < n; i++)
    matrix[i] = new int[m];

  // Fill matrix values
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> matrix[i][j];
    }
  }

  cout << findShortestPathValue(matrix, n, m, 0, 0); // (0,0) is the top left corner of the matrix (start point)

  cout << endl;
  delete[] matrix;
  return 0;
}