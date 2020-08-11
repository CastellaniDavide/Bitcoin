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
    btcVal = btcVal + C[0];

    for (int i = 1; i < misure; i++) {

        if (BTC >0)  {
            if (C[i]< 0){
                euro = BTC * btcVal;
                BTC = 0;
            }
            else
                ; // non vendo BC
        }
        else{ // ho euro
            if (C[i]>0){
                BTC = euro / btcVal;
                euro = 0;
            }
            else
                ; // non vendo euro

        }
        btcVal = btcVal + C[i];

    }
    if (BTC >0 ) {// vendi bitcoin
            euro = BTC * btcVal;
            BTC = 0;
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
