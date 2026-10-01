int ** convert(const int * t, size_t n, const size_t * lns, size_t rows)
{
    int ** mtx = new int*[rows];
    size_t p = 0;
    for (size_t i = 0; i < rows; ++i)
    {
        mtx[i] = new int[lns[i]];
        for (size_t j = 0; j < lns[i]; ++j)
        {
            mtx[i][j] = t[p++];
        }
    }
    return mtx;
}
