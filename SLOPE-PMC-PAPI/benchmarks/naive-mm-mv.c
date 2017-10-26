
/*--------------------------------------------------------*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>

/*--------------------------------------------------------*/

typedef int (*BFunctionPtr) (FILE * file, const char* arguments);

/*--------------------------------------------------------*/

int naiveMxv(
    FILE *fp,
    const char* arguments
)
{
    time_t t;

    unsigned int i, j, N = atoi(arguments);

    fprintf(fp, "Executable: naiveMxv, Arguments: %u\n", N);

    double* A = (double*)malloc(sizeof(double)*N*N);
    double* x = (double*)malloc(sizeof(double)*N);
    double* b = (double*)malloc(sizeof(double)*N);

    if ((A == NULL)
         || (x == NULL)
         || (b == NULL
       )
    )
    {
       fprintf(
          stderr,
          "Failed to allocate matrices, vectors\n"
       );
       exit(EXIT_FAILURE);
    }

    srand((unsigned)time(&t));

    for (i = 0; i < (N * N); i++)
    {
        A[i] = rand() % N;
    }

    for (i = 0; i < N; i++)
    {
        x[i] = rand() % N;
        b[i] = 0.;
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            b[i] += A[i*N + j] * x[j];
        }
    }

    fprintf(fp, "b[%d]=%f\n", N - 1, b[N - 1]);

    free(A);
    free(x);
    free(b);
}

/*--------------------------------------------------------*/

int naiveMxm(
    FILE * fp,
    const char* arguments
)
{
    time_t t;

    unsigned int i, j, k, N = atoi(arguments);

    fprintf(fp, "Executable: naiveMxm, Arguments: %u\n", N);

    double* a = (double*)malloc(sizeof(double)*N*N);
    double* b = (double*)malloc(sizeof(double)*N*N);
    double* c = (double*)malloc(sizeof(double)*N*N);

    if ((a == NULL)
         || (b == NULL)
         || (c == NULL
       )
    )
    {
       fprintf(
          stderr,
          "Failed to allocate matrices\n"
       );
       exit(EXIT_FAILURE);
    }

    srand((unsigned)time(&t));

    for (i = 0; i < (N * N); i++)
    {
        a[i] = rand() % N;
        b[i] = rand() % N;
        c[i] = 0.;
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            double tmp = 0.0;
            for (k = 0; k < N; k++)
            {
               tmp += a[i*N + k] * b[k*N + j];
            }
            c[i*N + j] += tmp;
        }
    }

    fprintf(fp, "C[%d]=%f\n", N*N - 1, c[N*N - 1]);

    free(a);
    free(b);
    free(c);
}


