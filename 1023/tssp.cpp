#include <stdio.h>
#include <string.h>
#include <algorithm>

#define max(a, b) ((a) > (b) ? (a) : (b))

int n;
int start[1500];
int end[1500];
int no[1500];

int cmp(int a, int b)
{
    if(end[a] != end[b]) {
        return end[a] < end[b];
    }
    return start[a] > start[b];
}

int calc()
{
    int ans = 0;
    int time = -1;
    for(int i = 0; i < n; i++) {
        if (time < start[no[i]]) {
            ans++;
            time = end[no[i]];
        }
    }
    return ans;
}

int main()
{
    while (scanf("%*d%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d%d", start+i, end+i);
            no[i] = i;
        }
        std::sort(no, no+n, cmp);

        printf("%d\n", calc());
    }
	return 0;
}

