#include <iostream>

using namespace std;

int factorial(int x)
{
    if(x==0 || x==1){
        return 1;
    }
    else{
        return x * fact(x-1);
    }
}

int sum_of_digits_of_number(int x)
{
    if(x==0){
        return 0;
    }
    else{
      return x%10 + sum_of_digits(x/10);
    }

}

int c = 0;

int reverse_number(int x)
{
    if(x==0){
        return 0;
    }
    else{
        c = c*10 + x%10;
        rev_num(x/10);
    }
    return c;
}

void decimal_to_binary(int x)
{
    if(x>0)
    {
        d_to_b(x/2);
        cout<<x%2;
    }
}

int power(int n, int x)
{
    if(x>1){
        return n*power(n,x-1);
    }
}
