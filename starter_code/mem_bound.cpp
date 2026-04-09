#pragma omp parallel for
for (size_t i = 0; i < N; i++)
{
    v[i] *= 2;
}