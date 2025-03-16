struct Point {
    int x;
    int y;
};

int main() {
    struct Point p1 = {1, 2};
    p1 = p1+1; // 오류: struct 태그를 표현식에서 사용하려고 함
    return 0;
}


