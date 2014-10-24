#include <stdio.h>
#include <string.h>
#include <algorithm>

#define max(a, b) ((a) > (b) ? (a) : (b))

int t, n;
int start[1500];
int end[1500];
int no[1500];
int dp[1500];

int cmp(int a, int b)
{
    if(start[a] != start[b]) {
        return start[a] < start[b];
    }
    return end[a] < end[b];
}

int calc()
{
    int ans = 0;
    for(int i = 0, j = 0; i <= t; i++) {
        ans = max(ans, dp[i]);
        if(j < n && i == start[no[j]]) {
            dp[end[no[j]]] = max(ans+1, dp[end[no[j]]]);
            j++;
            i--;
        }
    }
    return ans;
}

int main()
{
    while (scanf("%d%d", &t, &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d%d", start+i, end+i);
            end[i]++;
            no[i] = i;
        }
        std::sort(no, no+n, cmp);
        memset(dp, 0, sizeof(dp));

        printf("%d\n", calc());
    }
	return 0;
}

