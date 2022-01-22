#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::nothrow;

void clear_memory(bool **matrix, int row)
{
    for (int i = 0; i < row; ++i)
        delete[] matrix[i];
    delete[] matrix;
}

int mark_area(bool **matrix, int n, int m, int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m || matrix[x][y] == 0)
    {
        return 0;
    }

    matrix[x][y] = 0;
    int blocks = 1;

    for (int i = x - 1; i <= x + 1; ++i)
    {
        for (int j = y - 1; j <= y + 1; ++j)
        {
            blocks += mark_area(matrix, n, m, i, j);
        }
    }

    return blocks;
}

int areas(bool **matrix, int n, int m)
{
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (matrix[i][j] == 1)
            {
                // 6cout << "Area with " << mark_area(matrix, n, m, i, j) << " elements" << endl;
                mark_area(matrix, n, m, i, j);
                count++;
            }
        }
    }

    return count;
}

int main()
{
    int n, m;

    cin >> n >> m;
    while (n < 1 || n > 30 || m < 1 || m > 30)
    {
        cout << "1 <= N, M <= 30; Invalid entry, try again" << endl;
        cin >> n >> m;
    }

    bool **matrix = new (nothrow) bool *[n];
    if (!matrix)
    {
        std::cerr << "Invalid memory!" << endl;
        return 1;
    }

    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new (nothrow) bool[m];
        if (!matrix[i])
        {
            std::cerr << "Invalid memory!" << endl;
            clear_memory(matrix, i);
            return 1;
        }

        for (int j = 0; j < m; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    cout << areas(matrix, n, m) << " areas" << endl;

    clear_memory(matrix, n);

    return 0;
}

/*
Input:
6 7
1 1 0 0 0 1 0
0 0 0 0 0 0 0
1 1 1 0 0 1 0
1 1 1 0 0 0 0
0 0 0 0 1 1 1

Output:
5
*/