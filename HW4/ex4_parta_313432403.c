#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>

void print_quadratic(double a, double b, double c);

int find_roots(double a, double b, double c, double* p1, double* p2);

int main()
{
    double a, b, c;
    printf("Please enter three numbers:\n");
    scanf("%lf%lf%lf", &a, &b, &c);

    double r1, r2;
    int n = find_roots(a, b, c, &r1, &r2);

    print_quadratic(a, b, c);
    printf(" = 0 has ");

    switch (n) {
    case 0:
        printf("no real roots\n");
        break;
    case 1:
        printf("one real root: %g\n", r1);
        break;
    case 2:
        printf("two real roots: %g and %g\n", r1, r2);
        break;
    case -1:
        printf("infinite real roots\n");
        break;
    default:
        printf("%d roots? impossible!\n", n);
    }

    return 0;
}

void print_quadratic(double a, double b, double c)
{
    if(a == 0 && b == 0 && c == 0){
        printf("0");
        return;
    }
    if (a != 0){
        if (a == 1 || a == -1)
            printf("%sx^2", a < 0 ? "-" : "");
        else {
            printf("%gx^2", a);
        }
    }
    if (b != 0){
        if (b == 1 || b == -1)
            printf("%sx", a == 0 ? "" : b < 0 ? "-" : "+");
        else
            printf("%s%gx", a == 0 ? "" : b < 0 ? "-" : "+", b < 0 ? -b : b);
    }
    if (c != 0){
        printf("%s%g", a==0 && b==0 ? "" : c < 0 ? "-" : "+", c < 0 ? -c : c);
    }

}

int find_roots(double a, double b, double c, double* p1, double* p2)
{
    if (a == 0 && b == 0 && c == 0) {
        return -1; // Infinite roots
    }

    if (a == 0) {
        if (b == 0) {
            return 0; // No real roots
        }
        else {
            *p1 = -c / b; // Save the single root in p1
            return 1; // One root
        }
    }
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {

        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        *p1 = fmin(root1, root2); // Save the smaller root in p1
        *p2 = fmax(root1, root2); // Save the larger root in p2
        return 2; // Two roots
    }
    else if (discriminant == 0) {
        if (a == 0) {
            *p1 = -c / b; // Save the single root in p1
        }
        else {
            *p1 = -b / (2 * a); // Save the single root in p1
        }
        return 1; // One root
    }
    else {
        return 0; // No real roots
    }
}