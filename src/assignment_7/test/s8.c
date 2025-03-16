int main() {
    int sum = 0;
    int number;

    do {
        printf("Enter a number (enter a negative number to stop): ");
        scanf("%d", &number);

        if (number >= 0) {
            sum = sum + number;
        }
    } while (number >= 0);

    printf("The sum of the entered numbers is: %d\n", sum);
    printf("\n");

    return 0;
}

