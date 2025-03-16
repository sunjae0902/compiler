int main() {
    int arr[5];
    arr[0]=1;
    arr[1]=2;
    arr[2]=3;
    arr[3]=4;
    arr[4]=5;
    
    // 잘못된 배열 인덱스 접근
    printf("%d\n", arr[5]);  // arr 배열의 인덱스 범위는 0부터 4까지
    
    return 0;
}


