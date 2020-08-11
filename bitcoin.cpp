#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int C[MAXN];

double solve(int N, double E, int C[]) {
    // insert your code here
    return 42;
}

int main() {
    FILE *fr, *fw;
    int N, E, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &E));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &C[i]));

    fprintf(fw, "%.8f\n", solve(N, E, C));
    fclose(fr);
    fclose(fw);
    return 0;
}