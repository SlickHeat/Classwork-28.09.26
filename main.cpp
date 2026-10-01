#include <iostream>

void rmMtx(int ** mtx, size_t m)
{
    for (size_t i; i < m; ++i)
    {
        delete [] mtx[i];
    }
    
    delete [] mtx;
}

int ** makeMtx(size_t m, size_t n)
{
    int ** mtxR = new int * [m];

    try
    {
        for (size_t i = 0; i < m; ++i)
        {
            mtxR[i] = new int [n];
        }
    }
    catch (const std::bad_alloc & e)
    {
        rmMtx(mtxR, m);
        throw;
    }

    return mtxR;
}

void printMtx(int ** mtx, size_t m, size_t n)
{ 
  std::cout << mtx[0][0];
  for (size_t i = 1; i < n; ++i)
  {
    std::cout << " " << mtx[0][i];
  }

  for (size_t i = 1; i < m; i++)
  {
    std::cout << '\n' << mtx[i][0];
    for (size_t j = 1; j < n; ++j)
    {
        std::cout << " " << mtx[i][j]; 
    }
  }
}

int main() 
{
    size_t m = 0;
    size_t n = 0;
    std::cin >> m >> n;
    if (!std::cin || m==0 || n==0)
    {
        return 1;
    }
    int ** mtx = nullptr;
    try
    {
        mtx = makeMtx(m, n);
    }
    catch (const std::bad_alloc & e)
    {
        rmMtx(mtx, m);
        return 2;
    }
    for (size_t i = 0; i < m * n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            std::cin >> mtx[i][j];
        }
    }

    if (std::cin.fail())
    {
        rmMtx(mtx, m);
        return 1;
    }
    try
    {
        mtx = transpose(mtx, m, n);
    }
    catch (const std::bad_alloc & e)
    {
        rmMtx(mtx, m);
        return 2;
    }
    printMtx(mtx, m, n);
    rmMtx(mtx, m);
    return 0;
}
