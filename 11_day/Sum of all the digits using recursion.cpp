/*
int sumOfDigits(int n) {
    if (n == 0) 
    {
        return 0;
    } 
    else if (n < 0) 
    {
        return -sumOfDigits(-n);
    } 
    else 
    {
        return (n % 10) + sumOfDigits(n / 10);
    }

}
*/