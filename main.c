#include <stdio.h>
int modulas(int n,int m);
int power_num(int n,int power_n);
int modulas_exponent(int n,int m,int power);
int primality_test(int prime_candidate);
int pp;
int r;
int result_primality_test;
int main() {
    // Write C code here

    result_primality_test = primality_test(521);
    if(result_primality_test == 1)
    {
        printf("number maybe is prime \n ");
    }
    else
    {
        printf("number is composite \n");
    }

   //r = modulas_exponent(3,11,10);
   //printf("%i",r);
    return 0;
}

int modulas_exponent(int n_result,int m_prime_candidate,int power)
{
    int result = n_result;
    int binary_power = power;

    int binary_num = 0;
    int binary_bits[32] = {0};
    int bit_position = 0;
    int counter = 0;
    while(binary_power != 0)
    {
        binary_num = binary_power%2;
        binary_power = binary_power/2;
        binary_bits[bit_position] = binary_num;
        bit_position++;
    }
    while(bit_position > 0)
    {
        bit_position--;
        printf("bits ==>  %i \n",binary_bits[bit_position]);
        if ((binary_bits[bit_position] == 1) & (counter == 0))
        {
            counter++;
            continue;
        }
        counter++;
        if(binary_bits[bit_position] == 1) // square & multiply
        {
            result = power_num(result,2);
            result = result * n_result;
            result = modulas(result,m_prime_candidate);
            printf("result ==> %i \n",result);

        }
        else if (binary_bits[bit_position] == 0) // square
        {
            result = power_num(result,2);
            result = modulas(result,m_prime_candidate);
            printf("result ==> %i \n",result);
        }
        
    }
    return result;
}
int modulas(int n,int m)
{
    while (n >= m)
    {
        n = n - m;
    }

    return n;
}
int power_num(int n,int power_n)
{
    unsigned long long result = n;
    for(int i = 0; i < (power_n - 1);i++)
    {
        result = result * n;
    }
    return result;
}
int primality_test(int prime_candidate)
{
    long long result = 0;
    long long reminder = 0;
    long long  a[22] = {100,200,300,11,55,22,13,14,16,28,29,33,66,41,42,43,1000,4,5,6,2,3};
    long long security_test = 0;
    for (int i = 0 ;i <22 ;i++)
    {
        
        if(a[i] <= (prime_candidate - 2) && a[i] >= 2){
                printf("============================================\n");
                reminder = modulas_exponent(a[i],prime_candidate,prime_candidate-1);
                printf("============================================\n");
            if (reminder == 1){
                security_test +=1;
                
                if(security_test == 5)
                break;
            }
            else{
                security_test = 0;
                break;
            }
        }
    }
    printf("s = %i \n",security_test);
    if (security_test == 5)
    {return 1;}
    else
    {return 0;}
    
}