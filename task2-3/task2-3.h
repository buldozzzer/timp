// Поиск подстроки в строке.
// Простейший алгоритм.
// Алгоритм Рабина-Карпа.
// Сравнение времени выполнения реализаций указанных алгоритмов.

#ifndef TASK2_3_TASK2_3_H
#define TASK2_3_TASK2_3_H

#endif //TASK2_3_TASK2_3_H

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <vector>
#define tonum(c) (c >= 'A' && c <= 'Z' ? c - 'A' : c - 'a' + 26)
#define in_range(x,y,z) for (int x=y; x<z; x++)
typedef long long ll;

using namespace std;

int mod(int a,int p,int m)
{
    if (p == 0)
        return 1;
    int sqr = mod(a,p/2,m) % m;

    if (p & 1)
        return ((a % m) * sqr) % m;
    else
        return sqr;
}

int Naive_String_Matcher(const string T, const string P){

    int n=T.size();
    int m=P.size();
    for(int s=0; s<n-m; ++s){
        int temp=0;
        for(int i=0; i<m; i++){
            if(P[i]==T[s+i])
                temp++;
        }
        if(temp == m)
            return s;
    }
    return 0;
}
int Rabin_Karp_Matcher(const string T, const string P, int d, int q) {
    int n=T.size();
    int m=P.size();
    int h = mod(d, m-1, q);
    int p=0;
    int t = 0;
    bool flag;
    for (int i=0; i<m; ++i){                //Предварительная обработка
        t = (d*t + tonum(T[i]))%q;
        p = (d*p+tonum(P[i]))%q;
    }
    for (int s=0; s<n-m; ++s){              //Сравнение

        if(p==t) {
            flag = true;
            for (int i = 0; i < m; i++) {
                if (tonum(P[i]) != tonum(T[s + i]))
                    flag = false;
            }
        }
        if(flag)
            return s;
        if (s<n-m) {
            t = (d * (t - (tonum(T[s]) * h)%q) + tonum(T[s + m]))%q;
        }
    }
    return 0;
}
