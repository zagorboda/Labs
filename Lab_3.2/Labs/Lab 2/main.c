#include <stdio.h>
#include <stdlib.h>

int main()
{

    float a, b, c, p, P, s, h_a, h_b, h_c, m_a, m_b, m_c, b_a, b_b, b_c;

    printf("Enter sides: ");

    while(1){
        scanf("%f %f %f", &a, &b, &c);
        if (a + b > c && a + c > b && b + c > a){
            break;
        }
        else{
            printf("Try another value");
        }
    }

    P = a + b + c;
    p = P / 2;

    s = sqrt(p*(p - a)*(p - b)*(p - c));

    h_a = (2 * s) / a;
    h_b = (2 * s) / b;
    h_c = (2 * s) / c;

    m_a = 0.5 * sqrt(2 * b * b + 2 * c * c - a * a);
    m_b = 0.5 * sqrt(2 * a * a + 2 * c * c - b * b);
    m_c = 0.5 * sqrt(2 * b * b + 2 * a * a - c * c);

    b_a = (2 / (b + c))*sqrt(b * c * p * (p - a));
    b_b = (2 / (a + c))*sqrt(a * c * p * (p - b));
    b_c = (2 / (b + a))*sqrt(b * a * p * (p - c));

    printf("P = %f\n", P);
    printf("p = %f\n", p);
    printf("s = %f\n", s);
    printf("h_a = %f\n", h_a);
    printf("h_b = %f\n", h_b);
    printf("h_c = %f\n", h_c);
    printf("m_a = %f\n", m_a);
    printf("m_b = %f\n", m_b);
    printf("m_c = %f\n", m_c);
    printf("b_a = %f\n", b_a);
    printf("b_b = %f\n", b_b);
    printf("b_c = %f\n", b_c);

    getch();

    return 0;
}
