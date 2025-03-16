int main() {
    float value = 3.14;
    float x;
    switch ((int)value) {
        case x: // 오류: 부동 소수점 리터럴은 case 레이블로 사용할 수 없음
            printf("Value is 3.14\n");
            break;
        default:
            printf("Value is not 3.14\n");
    }

    return 0;
}

