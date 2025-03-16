// jump statement

int fun(){
    int i;
    while(i++<10){
        if(i==2)
            break;
        else
            continue;
    }
    return i;
}

int main(){
    return fun();
}

