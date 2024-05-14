

// 잘못된 나열형(enum) 정의
enum Weekday {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday
};

int main() {
    enum Weekday today = Monday; // 성립
    today = Saturday; // 존재하지 않는 값 사용 (오류)
    printf("Today is: %d\n", today);
    return 0;
}

