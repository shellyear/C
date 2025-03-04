#include <stdio.h>

/*
 * This program demonstrates floating-point representation in C
 * and explains why some numbers experience rounding errors while others do not.
 *
 * Floating-point numbers in C use the IEEE 754 single-precision format,
 * which consists of:
 *   - 1 bit for the sign
 *   - 8 bits for the exponent (biased by 127)
 *   - 23 bits for the fraction (mantissa)
 *
 * Due to this representation, some decimal numbers can be stored exactly,
 * while others suffer from rounding errors because they require an infinite
 * number of bits in binary.
 */

int main() {
    float floatNum = 75.25; // No rounding error
    float height = 13.3;    // Rounding error occurs

    /*
     * Conversion of 75.25 to binary:
     * ------------------------------
     * Step 1: Convert the integer part (75) to binary:
     *   75 (decimal) = 1001011 (binary)
     *
     * Step 2: Convert the fractional part (0.25) to binary:
     *   0.25 × 2 = 0.5   → integer part = 0
     *   0.5 × 2  = 1.0   → integer part = 1 (end)
     *   So, 0.25 (decimal) = 0.01 (binary)
     *
     * Step 3: Combine the integer and fractional parts:
     *   75.25 (decimal) = 1001011.01 (binary)
     *
     * Step 4: Normalize to scientific notation:
     *   1.00101101 × 2^6 // it means move the decimal point left 6 places to put it after the first 1 in 1001011.01
     * // so 1.00101101 × 2^6 === 1001011.01
     * 
     * Step 5: Encode in IEEE 754 format:
     *   - Sign bit: 0 (positive)
     *   - Exponent: 6 + 127 = 133 (binary: 10000101)
     *   - Mantissa: 00101101000000000000000 (fits exactly in 23 bits)
     *
     * Final IEEE 754 binary representation:
     *   0 10000101 00101101000000000000000
     *
     * Since the mantissa fits within 23 bits, **no rounding error occurs**.
     */

    /*
     * Conversion of 13.3 to binary:
     * ------------------------------
     * Step 1: Convert the integer part (13) to binary:
     *   13 (decimal) = 1101 (binary)
     *
     * Step 2: Convert the fractional part (0.3) to binary:
     *   0.3 × 2 = 0.6   → integer part = 0
     *   0.6 × 2 = 1.2   → integer part = 1
     *   0.2 × 2 = 0.4   → integer part = 0
     *   0.4 × 2 = 0.8   → integer part = 0
     *   0.8 × 2 = 1.6   → integer part = 1
     *   0.6 × 2 = 1.2   → integer part = 1
     *   (Repeating pattern: 0100110011001100110011...)
     *
     * Step 3: Combine the integer and fractional parts:
     *   13.3 (decimal) ≈ 1101.0100110011001100110011... (binary, infinite)
     *
     * Step 4: Normalize to scientific notation:
     *   1.10101001100110011001101 × 2^3
     *
     * Step 5: Encode in IEEE 754 format:
     *   - Sign bit: 0 (positive)
     *   - Exponent: 3 + 127 = 130 (binary: 10000010)
     *   - Mantissa (rounded to 23 bits): 10101001100110011001101
     *
     * Final IEEE 754 binary representation (approximate):
     *   0 10000010 10101001100110011001101
     *
     * Since the binary fraction of 0.3 is **infinite**, IEEE 754 **truncates it to 23 bits**,
     * causing a small rounding error.
     */

    // Printing with high precision to observe the rounding error
    printf("%.23f\n", floatNum); // No rounding error
    printf("%.23f", height); // Small rounding error visible

    return 0;
}
