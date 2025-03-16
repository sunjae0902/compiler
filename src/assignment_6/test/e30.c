int fun(){return 0;}
union IllegalUnion {
    int a;
    int fun(); // 84
    float c;
};

