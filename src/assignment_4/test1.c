
// declaration

int global_variable = 1 // 세미콜론 누락

// 함수 선언
float add(int a, int b);

int main() {
    // 지역 변수 선언
    int local_variable = 20;
    char c = 'a';
    float f = 2.44;
    void *vp;
    
    // 함수 호출
    int result = add(global_variable, local_variable);
    printf("Result: %d\n", result);

    return 0;
}

// 함수 정의
float add(int a, int b) {
    return a + b;
}

