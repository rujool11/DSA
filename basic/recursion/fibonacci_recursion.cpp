int createFib(int n) {
    if (n==1) {return 0;}
    else if (n==2) { return 1;}
    else {
        return createFib(n-1) + createFib(n-2);
    }
}

vector<int> generateFibonacciNumbers(int n) {
    vector<int> fibs;

    for (int i=0;i<n;i++){
        fibs.push_back(createFib(i+1));
    }

    return fibs;
}

