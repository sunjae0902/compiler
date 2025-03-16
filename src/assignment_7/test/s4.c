float div(int a, int b){
    int result;
    if(b==0)
        printf("Divided by Zero\n");
    printf("\n");
    return (float)a/b;
}

int main(){
    float result;
    result = div(10,3);
    printf("%f\n",result);
    printf("\n");
}
