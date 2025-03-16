int multiply(int a,int b){
    int result=0;
    while(a){
        if(a%2){
            result = result+b;
        }
        a = a/2;
        b = b*2;
    }
    return result;
}

int main(){
    int i;
    i=multiply(100,34);
    printf("result: %d\n",i);
    printf("\n");
    return 0;
}
