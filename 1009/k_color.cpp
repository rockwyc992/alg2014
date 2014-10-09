#include <stdio.h>
#include <string.h>

char map[20][20];
int add[20][20];

void init(int n, int k) {
    memset(add, -1, sizeof(add));
    for (int i = 0; i <= n ;i++) {
        add[i][0] = add[0][i] = 0;
    }
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            if (map[x][y] == k) {
                add[x][y] = 1;
            }
        }
    }
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            add[x][y] += add[x][y-1] + add[x-1][y];
            add[x][y] -= add[x-1][y-1];
        }
    }
}

int calc(int n, int k)
{
    init(n, k);
    int max = 0;
    for (int x1 = 0; x1 <= n; x1++) {
        for (int x2 = 0; x2 <= x1; x2++) {
            for (int y1 = 0; y1 <= n; y1++) {
                for (int y2 = 0; y2 <= y1; y2++) {
                    int now = add[x1][y1] + add[x2][y2];
                    now -= add[x1][y2] + add[x2][y1];
                    if (max < now) {
                        max = now;
                    }
                }    
            }
        }
    }
    return max;
}

int main()
{
    int n;
    int k;
    while (scanf("%d%d", &n, &k) != EOF) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", map[i] + j);
            }
        }

        for (int i = 1; i <= k; i++) {
            printf("%d->%d\n", i, calc(n, i));
        }
        puts("");
    }
	return 0;
}

