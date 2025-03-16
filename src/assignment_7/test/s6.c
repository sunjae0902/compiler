int a[10];
int binary_search(int arr[], int size, int target) {
    int left,right;
    right = size - 1;

    while (left <= right) {
        int mid;
        mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        
        if (arr[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    
    // 값을 찾지 못하면 -1 반환
    return -1;
}


int main() {
    int target, size, result;
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    a[4] = 4;
    a[5] = 5;
    a[6] = 6;
    a[7] = 7;
    a[8] = 8;
    a[9] = 9;
    size = sizeof(a) / sizeof(a[0]);
    
    printf("Enter the value to search: ");
    scanf("%d", &target);

    result = binary_search(a, size, target);
    
    if (result != -1) {
        printf("Value %d found at index %d.\n", target, result);
    } else {
        printf("Value %d not found in the array.\n", target);
    }
    printf("\n");
    return 0;
}

