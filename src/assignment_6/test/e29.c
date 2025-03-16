int fun(int);

struct s{
    int a;
};

int main(){
    struct s ss;
    return fun(ss); // 59
}

