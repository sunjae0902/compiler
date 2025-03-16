// 오류: 함수가 배열 타입을 반환할 수 없음
int myArrayFunction()[10] {
    static int arr[10] = {0};
    return arr; // 유효하지 않은 반환 타입
}

int main() {
    int *arr = myArrayFunction();
    return 0;
}

