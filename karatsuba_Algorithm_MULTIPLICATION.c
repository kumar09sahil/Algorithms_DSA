/* C program to implement “Karatsuba Algorithm” to multiply two large integers.
*/
#include<stdio.h>
#include<math.h>
long long power(long s) {
    long long result = 1;
    while (s > 0) {
        result *= 10;
        s--;
    }
    return result;
}

long length(long a)
{
    long l=0;
    while(a>0)
    {
        a/=10;
        l++;
    }
    return l;
}
long long karatsuba(long long x,long long y)
{
    if(x<10 || y<10)
    {
        return x*y;
    }
    int n=fmax(length(x),length(y));
    int n1=n/2;
    long long A1= x / power(n1);
    long long A2=x%power(n1);
    long long B1= y / power(n1);
    long long B2=y%power(n1);
    long long C=karatsuba(A1,B1);
    long long D=karatsuba(A2,B2);
    long long E=karatsuba(A1-A2,B1-B2);
    long long F=C+D-E;
    long long P= C*power(n)+F*power(n1)+D;
    return P;

}



int main()
{
    long long a;
    long long b;
    printf("enter the first number : ");
    scanf("%lld",&a);
    printf("enter the second number :"); 
    scanf("%lld",&b);
    long long result=karatsuba(a,b);
    printf("\nMultiplication result : %lld",result);
    
    return 0;
}