void calculate(int numbers[], int size, int *max, int *min,float *avg);

int main() {
    int numbers[10];
    int max, min, sum,i;
    float avg;
    
    printf("Enter 10 integers: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &numbers[i]);
    }

    calculate(numbers, 10, &max, &min, &avg);

    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);
    printf("Average: %f\n", avg);
    printf("\n");

    return 0;
}
// 최대, 최소, 평균 계산
void calculate(int numbers[], int size, int *max, int *min, float *avg) {
    int i,*sum;
    *max = numbers[0];
    *min = numbers[0];

    for (i = 0; i < size; i++) {
        if (numbers[i] > *max) {
            *max = numbers[i];
        }
        if (numbers[i] < *min) {
            *min = numbers[i];
        }
        *sum = *sum+ numbers[i];
    }

    *avg = *sum / (float)size;
}

