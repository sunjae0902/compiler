int fibonacci(int n) {
    int a = 0, b = 1, next,i;
    if (n <= 1)
        return n;
    for (i = 2; i <= n; i++) {
        b = fibonacci(n-2)+fibonacci(n-1);
    }
    return b;
}

int main() {
    int num;
    printf("Enter the position of the Fibonacci sequence: ");
    scanf("%d", &num);
    if (num < 0)
        printf("Please enter a non-negative integer.\n");
    else
        printf("The %dth Fibonacci number is %d\n", num, fibonacci(num));
    printf("\n");
    return 0;
}


