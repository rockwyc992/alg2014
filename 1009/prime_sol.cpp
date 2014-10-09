#include <stdio.h>
#include <string.h>

int prime[350];
int sol[200][350];

int top;
int str[200];

void init();
void init_prime();
void init_sol();
void calc(int n, int s);

int main()
{
    int n;
    int s;
    init();

    while (scanf("%d%d", &n, &s) != EOF) {
        if (n*2 > s) {
            puts("");
            continue;
        } else if (sol[n][s]) {
            top = 0;
            calc(n, s);
        } else {
            puts("");
            continue;
        }
    }
	return 0;
}

void init_prime() 
{
    memset(prime, 0, sizeof(prime));
    for(int i = 3; i <= 300; i += 2) {
        prime[i] = 1;
    }
    prime[2] = 1;
    for (int i = 3; i <= 300; i += 2) {
        if (prime[i]) {
            for (int j = i*2; j<=300; j += i) {
                prime[j] = 0;
            }
        }
    }
}

void init_sol()
{
    memset(sol, 0, sizeof(sol));
    sol[0][0] = 1;
    for (int k = 0; k <= 150 ; k++) {
        for (int i = 2; i <= 300; i++) {
            for (int j = 2; j <= 300 ; j++) {
                if (j > i) {
                    break;
                }
                if (prime[j]) {
                    if (sol[k][i - j]) {
                        sol[k + 1][i] = 1;
                        break;
                    }
                }
            }
        }
    }
}

void init() 
{
    init_prime();
    init_sol();
}

void calc(int n, int s)
{
    if(n < 0) {
        return;
    } else if (n == 0) {
        printf("%d", str[0]);
        for(int i = 1; i < top; i++) {
            printf(" %d", str[i]);
        }
        puts("");
        return;
    }
    
    for (int i = 2; i <= s; i++) {
        if (prime[i] && sol[n-1][s-i]) {
            str[top++] = i;
            calc(n-1, s-i);
            top--;
        }
    }
}

