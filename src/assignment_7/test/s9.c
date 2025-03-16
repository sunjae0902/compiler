char calculateGrade(int score);

int main() {
    int score;
    char grade;
    printf("점수 입력 (0-100): ");
    scanf("%d", &score);
    
    grade = calculateGrade(score);
    
    printf("Your grade is: %c\n", grade);
    printf("\n");
    return 0;
}

char calculateGrade(int score) {
    char grade;

    if (score >= 90) {
        grade = 'A';
    } else if (score >= 80) {
        grade = 'B';
    } else if (score >= 70) {
        grade = 'C';
    } else if (score >= 60) {
        grade = 'D';
    } else {
        grade = 'F';
    }

    return grade;
}

