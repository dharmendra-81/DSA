// Decimal to Binary
string decimalToBinary(int decimal) {
    if (decimal == 0) return "0";
    string binary = "";
    while (decimal > 0) {
        binary = to_string(decimal % 2) + binary;
        decimal /= 2;
    }
    return binary;
}

// Binary to Decimal
int binaryToDecimal(string binary) {
    int decimal = 0;
    int base = 1; // 2^0

    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2; // Move to the next power of 2
    }

    return decimal;
}