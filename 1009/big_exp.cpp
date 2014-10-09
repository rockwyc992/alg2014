#include <stdio.h>
#include <string.h>
#include <math.h>

struct bignum
{
    char str[2100];
    int len;

    void init()
    {
        memset(this->str, 0, sizeof(this->str));
        this->len = 0;
    }

    void zero() 
    {
        this->init();
        this->len = 1;
    }

    bignum operator = (int a) 
    {
        if (a == 0) {
            this->zero();
            return *this; 
        }
        this->init();
        while (a) {
            str[len++] = a%10;
            a /= 10;
        }
        return *this;
    }

    bignum operator += (bignum a)
    {
        return *this = *this + a;
    }

    bignum operator + (bignum a)
    {
        if (this->len > a.len) {
            a.len = this->len;
        }
        for (int i = 0; i < a.len; i++) {
            a.str[i] += this->str[i];
            if (a.str[i] >= 10) {
                a.str[i] -= 10;
                a.str[i + 1]++;
            }
        }
        if(a.str[a.len]) {
            a.len++;
        }
        return a;
    }

    void print() {
        for(int i = len-1; i >= 0; i--) {
            putchar(str[i] + '0');
        }
        puts("");
    }
};

bignum base[5600];
void init_base();

int main()
{
    int n;
    int m;
    bignum ans;
    init_base();
    while (scanf("%d%d", &n, &m) != EOF) {
        ans = 0;
        ans += base[n];
        ans += base[m];
        ans.print();
    }
	return 0;
}

void init_base()
{
    base[0] = 1;
    for(int i = 1 ; i <= 5555; i++) {
        base[i] = base[i-1] + base[i-1];
    }
}

