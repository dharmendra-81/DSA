int LCM(int a, int b) {
    int maxNum = (a > b) ? a : b; 
    int lcm = maxNum;
    while (true) {
        if (lcm % a == 0 && lcm % b == 0) {
            return lcm; 
        }
        lcm++;
    }
}