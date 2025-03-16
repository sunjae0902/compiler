int reverseNumber(int num) {
    int reversed;
    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num = num / 10;
    }
    return reversed;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Reversed number is %d\n", reverseNumber(num));
    printf("\n");
    return 0;
}

