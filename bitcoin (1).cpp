#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int C[MAXN];

double solve(int N, double E, int C[]) {
    double btcVal = E;
    double BTC = 1;
    double euro;
    int misure = N;
    int prezzoIniziale = E;

    if (C[0] < 0) {
        euro = BTC * btcVal;
        BTC = 0;
    }
    else {
        BTC = 1;
        euro = 0;
    }

    for (int i = 0; i < misure; i++) {

        btcVal = btcVal + C[i];

        if (C[i] > 0 && C[i + 1] < 0 || i == misure - 1) {
            euro = BTC * btcVal;
            BTC = 0;
        }

        if (C[i + 1] > 0 && C[i] < 0) {
            BTC = euro / btcVal;
            euro = 0;
        }

    }
    return euro;
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
