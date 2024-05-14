// iteration statement
void for_iteration(){
    int i;
    for(i=0;i<10;i++){
        printf("%d\n",i);
    }
    while(i++ < 10){
        printf("%d",i);
    }
}

void while_iteration(){
    int i = 0;
    while(i++ < 10){
        printf("%d",i);
    }
}

void do_while_iteration(){
    int i = 2;
    do{
        printf("hello");
    }while(i++<10);
}

// selection statement
void select(int k){
    if(k >= 0) 
        printf("positive\n");
    else
        printf("negative\n");
    return;
}

