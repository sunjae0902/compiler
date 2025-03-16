 // 수식
int b = 2, c = 5, d = 3, e = 9, f = 10, g = 11, h = 12, k=13, l=14;
float expr(){
    char c = 'a';
    int a = 0;
    float result = (float)(++a + b * c) / (d - e) + (f % g) * h -  (k * l);
    return result;
}

int main(){
    float result = expr();
 
    return 0;
    
}
