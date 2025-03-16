int gcd(int a, int b){
    while(a!=b){
        if(a<b)
            b=b-a;
        else
            a=a-b;
    }
    return a;
}

int main() {
    int num1, num2;

    // 사용자로부터 두 정수를 입력 받음
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // 최대공약수를 계산하고 출력
    printf("gcd of %d and %d is %d\n", num1, num2, gcd(num1, num2));
    printf("\n");
    return 0;
}

