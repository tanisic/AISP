

#include <iostream>
#include<time.h>
#include<vector>
#include "StogPovezaniPopis.cpp"
#include"StogNiz.cpp"
int Povrh(int n, int m)
{
    if (n == m || m == 0) return 1;
    return Povrh(n - 1, m - 1) + Povrh(n - 1, m);
}
int PovrhStogNiz(int a, int b) {
   
    
    int n, m;
    Stog s1 = Stog(1000);
    Stog s2 = Stog(1000);
    s1.Push(a);
    s2.Push(b);
    int povrh = 0;
    do {
        n = s1.Pop();
        m = s2.Pop();
        if (m == n || n == 1 || m == 0) povrh++;
        else {
            s1.Push(n - 1);
            s2.Push(m - 1);
            s1.Push(n - 1);
            s2.Push(m);
        }
    
    } while (!s1.IsEmpty());
   
        return povrh;
}
int PovrhStogPovezaniPopis(int a, int b)
{
    
    int n, m;
    StogPP s;
    s.Push(a);
    s.Push(b);
    int povrh = 0;
    do {
        m = s.Pop();
        n = s.Pop();
        if (m == n || n == 0 ) povrh++;
        else
        {
            s.Push(n - 1);
            s.Push(m - 1);
            s.Push(n - 1);
            s.Push(m);
        }
    } while (!s.IsEmpty());
    
    
    return povrh;
}
int main()
{
    int n;
    std::cout << "Unesite n: " << std::endl;
    std::cin >> n;
    int m = n / 2;
    time_t t;
    t = clock();
    int povrh = Povrh(n, m);
    t = clock() - t;
    std::cout << "REZULTAT POVRHA: " << povrh << std::endl;
    std::cout << "Povrh rekurzija vrijeme u ms: " << t << std::endl;
    t = clock();
    PovrhStogNiz(n, m);
    t = clock() - t;
    std::cout << "Povrh Stog sa nizom vrijeme u ms: " << t << std::endl;
    t = clock();
    PovrhStogPovezaniPopis(n, m);
    t = clock() - t;
    std::cout << "Povrh Stog sa povezanim popisom vrijeme u ms: " << t  << std::endl;
}

