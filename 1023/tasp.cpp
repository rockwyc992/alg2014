#include <stdio.h>
#include <algorithm>

int n;
int fir[110];
int sec[110];
int no[110];

bool cmp (int a, int b)
{
    if (fir[a] < sec[a]) {
        if (fir[b] < sec[b]) {
            return fir[a] < fir[b];
        } else {
            return true;
        }
    } else {
        if (fir[b] < sec[b]) {
            return false;
        } else {
            return sec[a] > sec[b];
        }
    }
}

int main()
{
    while(scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d%d", fir+i, sec+i);
            no[i] = i;
        }
        std::sort(no, no + n, cmp);

        int count_fir = 0;
        int count_sec = 0;
        for(int i = 0; i < n; i++) {
            count_fir += fir[no[i]];
            count_sec = std::max(count_sec, count_fir) + sec[no[i]];
        }

        printf("%d\n", count_sec);
    }
	return 0;
}

