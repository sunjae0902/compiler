

// 불완전한 구조체 선언
struct Node;

void printNode(struct Node *node); // 참조

// 정의
struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node n1 = {10, 0};
    struct Node n2 = {20, &n1}; // n2가 n1을 가리킴

    return 0;
}

