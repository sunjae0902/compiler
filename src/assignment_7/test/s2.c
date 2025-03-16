int gcd(int a, int b){
    while(a != b){
        if(a < b)
            b = b - a;
        else
            a = a - b;
    }
    return a;
}

// 최소공배수를 구하는 함수
int lcm(int a, int b) {
    return a * (b / gcd(a, b));
}

int main() {
    int num1, num2;

    // 사용자로부터 두 정수를 입력 받음
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // 최소공배수를 계산하고 출력
    printf("LCM of %d and %d is %d\n", num1, num2, lcm(num1, num2));
    printf("\n");
    return 0;
}


