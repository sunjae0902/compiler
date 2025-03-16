// 파라미터 타입 불일치
void myFunction(int x, int y) {}

int main() {
    char *s;
    int arr[2];
    myFunction(&s, arr);
    return 0;
}


