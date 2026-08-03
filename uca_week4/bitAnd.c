#include<stdio.h>

int bitAND(int num1 , int num2){
    int res = ~(~num1 | ~num2);
    return res;
}

int main(){
    int num1;
    int num2;
    printf("Enter num1 and num2: ");
    scanf("%d",&num1);
    scanf("%d",&num2);

    int num1ANDnum2 = bitAND(num1,num2);

    printf("AND of num1 and num2 using (~ and |): %d", num1ANDnum2);
}