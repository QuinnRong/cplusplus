#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int ZeroOneBagCore(int* weight, int* value, int** f, int N, int W, int n, int w)
{
    if (n < 0 || w < 0) return 0;
    if (w == 0) f[n][w] = 0;
    if (f[n][w] >= 0) return f[n][w];

    int res0 = ZeroOneBagCore(weight, value, f, N, W, n - 1, w);
    int res1 = 0;
    if (w >= weight[n])
        res1 = ZeroOneBagCore(weight, value, f, N, W, n - 1, w - weight[n]) + value[n];
    f[n][w] = (res0 > res1) ? res0 : res1;
    return f[n][w];
}

int ZeroOneBag(int* weight, int* value, int N, int W)
{   /*
    input: array of weight and array of value whose length is N; the bag size W
    output: maximum sum of value that can put into the bag
    */
    if (weight == nullptr || value == nullptr || N <= 0 || W <= 0) return 0;
    int** f = new int*[N];
    for (int i = 0; i < N; ++i)
    {
        f[i] = new int[W + 1];
        for (int j = 0; j <= W; ++j)
        {
            f[i][j] = -1;
        }
    }

    int res = ZeroOneBagCore(weight, value, f, N, W, N - 1, W);

    // print the map (N * (W + 1))
    // for (int i = 0; i < N; ++i)
    // {
    //  for (int j = 0; j <= W; ++j)
    //      printf("%4d", f[i][j]);;
    //  printf("\n");;
    // }
    delete[] f;

    // find the selection method
    // int* path = new int[N];
    // int copy_w = W;
    // for (int i = N - 1; i > 0; --i)
    // {
    //     if (f[i - 1][copy_w] == f[i][copy_w])
    //         path[i] = 0;
    //     else if (f[i - 1][copy_w - weight[i]] == f[i][copy_w] - value[i])
    //     {
    //         path[i] = 1;
    //         copy_w -= weight[i];
    //     }
    //     else
    //         cout << "Error" << endl;
    // }
    // if (copy_w >= weight[0])
    //     path[0] = 1;
    // else
    //     path[0] = 0;
    // for (int i = 0; i < N; ++i) printf("%d ", path[i]);
    // printf("\n");
    // delete[] path;

    return res;
}

int main()
{
    freopen("2.txt", "r", stdin);
    int W, N;
    cin >> W >> N;

    int* weight = new int[N];
    int* value = new int[N];

    for (int i = 0; i < N; ++i)
    {
        cin >> weight[i] >> value[i];
    }

    int res = ZeroOneBag(weight, value, N, W);
    printf("%d\n", res);

    delete[] weight;
    delete[] value;
    fclose(stdin);
    return 0;
}