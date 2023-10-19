
def main():
    print("Assignment 1 results...\n")
    
    # Question 8
    BINARY_STRING = "1000101001101001"
    decimal = binary_to_decimal(BINARY_STRING)
    print(f"Question 8: {decimal}")

    # Question 9
    DECIMAL_INT = 35433
    hexadecimal = decimal_to_hexadecimal(DECIMAL_INT)
    print(f"Question 9: {hexadecimal}")

    # Question 10
    HEX_STRING_1 = "A4988"
    HEX_STRING_2 = "6BD"
    hexadecimal2 = add_hexadecimal(HEX_STRING_1, HEX_STRING_2)
    print(f"Question 10: {hexadecimal2}")

    #Question 11
    BINARY_STRING_2 = "10001000"
    BINARY_STRING_3 = "00000101"
    binary = binary_subtraction(BINARY_STRING_2, BINARY_STRING_3)
    print(f"Question 11: {binary}")

    # Two more examples for question 11
    BINARY_STRING_4 = "10101110"
    BINARY_STRING_5 = "01011101"
    binary2 = binary_subtraction(BINARY_STRING_4, BINARY_STRING_5)
    print(f"Example 2: {binary2}")

    BINARY_STRING_6 = "11110100"
    BINARY_STRING_7 = "01101101"
    binary3 = binary_subtraction(BINARY_STRING_6, BINARY_STRING_7)
    print(F"Example 3: {binary3}")

    
# Question 8
def binary_to_decimal(binaryString):
    decimal = 0

    reversedBinaryString = binaryString[::-1]

    for i in range(len(binaryString)):
        if reversedBinaryString[i] == "1":
            decimal = decimal + (2**i)

    return decimal

# Question 9
def decimal_to_hexadecimal(decimalInt):
    hexadecimalMap = {
        0: "0", 1: "1", 2: "2", 3: "3", 
        4: "4", 5: "5", 6: "6", 7: "7", 
        8: "8", 9: "9", 10: "A", 11: "B",
        12: "C", 13: "D", 14: "E", 15: "F"
    }

    hexadecimal = ""
    quotient = decimalInt
    remainder = 0

    while quotient != 0:
        remainder = quotient % 16
        quotient = quotient // 16
        hexadecimal = hexadecimal + hexadecimalMap[remainder]

    return hexadecimal[::-1]

# Question 10
def add_hexadecimal(hexString1, hexString2):
    hexToDecimalMap = {
        "0": 0, "1": 1, "2": 2, "3": 3, 
        "4": 4, "5": 5, "6": 6, "7": 7, 
        "8": 8, "9": 9, "A": 10, "B": 11,
        "C": 12, "D": 13, "E": 14, "F": 15
    }

    decimalToHexMap = {
        0: "0", 1: "1", 2: "2", 3: "3", 
        4: "4", 5: "5", 6: "6", 7: "7", 
        8: "8", 9: "9", 10: "A", 11: "B",
        12: "C", 13: "D", 14: "E", 15: "F"
    }

    maxLen = max(len(hexString1), len(hexString1))

    hexString1 = hexString1.zfill(maxLen)
    hexString2 = hexString2.zfill(maxLen)

    revHexString1 = hexString1[::-1]
    revHexString2 = hexString2[::-1]

    hexadecimalSum = ""
    carry = 0

    for i in range(maxLen):
        sum = hexToDecimalMap[revHexString1[i]] + hexToDecimalMap[revHexString2[i]] + carry
        remainder = sum % 16
        hexadecimalSum = hexadecimalSum + decimalToHexMap[remainder]
        carry = sum // 16

    if carry == 1:
        hexadecimalSum = hexadecimalSum + decimalToHexMap[carry]
        
    return hexadecimalSum[::-1]

# Question 11
def binary_subtraction(binaryString1, binaryString2):
    twosComplement = ""

    for i in range(len(binaryString2)):
        if binaryString2[i] == "1":
            twosComplement = twosComplement + "0"
        else:
            twosComplement = twosComplement + "1"
    
    twosComplement = binary_addition(twosComplement, "00000001")
    return binary_addition(binaryString1, twosComplement)
    

# Binary addition function to be used in binary subtraction
def binary_addition(binaryString1, binaryString2):
    maxLen = max(len(binaryString1), len(binaryString2))

    binaryString1 = binaryString1.zfill(maxLen)
    binaryString2 = binaryString2.zfill(maxLen)

    revBinaryString1 = binaryString1[::-1]
    revBinaryString2 = binaryString2[::-1]

    finalBinary = ""
    carry = 0

    for i in range(maxLen):
        sum = int(revBinaryString1[i]) + int(revBinaryString2[i]) + carry
        finalBinary = finalBinary + ('1' if sum % 2 == 1 else '0')
        carry = sum // 2

    return finalBinary[::-1]




    
if __name__ == "__main__":
    main()
