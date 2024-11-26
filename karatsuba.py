def brute_force_multiply(num1, num2):
    return str(int(num1) * int(num2))

def karatsuba_multiply(x, y):
    # Base case for recursion
    if len(x) == 0 or len(y) == 0:
        return '0'
    if len(x) == 1 or len(y) == 1:
        return str(int(x) * int(y))
    
    # Ensure both numbers are of the same length by padding with zeros
    max_len = max(len(x), len(y))
    x = x.zfill(max_len)
    y = y.zfill(max_len)

    n = len(x)
    half = n // 2

    # Split the digit sequences
    a, b = x[:-half], x[-half:]
    c, d = y[:-half], y[-half:]

    # Recursive calls
    z0 = karatsuba_multiply(b, d)  # b * d
    z1 = karatsuba_multiply(str(int(a) + int(b)), str(int(c) + int(d)))  # (a + b)(c + d)
    z2 = karatsuba_multiply(a, c)  # a * c

    # Combine results
    return str(int(z2) * (10 ** (2 * half)) + (int(z1) - int(z2) - int(z0)) * (10 ** half) + int(z0))

# Test Cases
test_cases = [
    ("1234567890", "9876543210"),  # Positive Test Case
    ("12345678901234567890", "98765432109876543210"),  # Positive Test Case
    ("0", "1234567890"),  # Positive Test Case
    ("invalidInput", "1234567890"),  # Negative Test Case
    ("1234567890", "invalidInput"),  # Negative Test Case
    ("99999999999999999999", "12345678901234567890")  # Positive Test Case
]

print("Testing Brute Force and Karatsuba Multiplication:")
for i, (num1, num2) in enumerate(test_cases):
    try:
        # Validate inputs
        if not num1.isdigit() or not num2.isdigit():
            raise ValueError("Invalid input")
        
        brute_result = brute_force_multiply(num1, num2)
        karatsuba_result = karatsuba_multiply(num1, num2)
        
        print(f"Test Case {i + 1}:")
        print(f"  Brute Force Result: {brute_result}")
        print(f"  Karatsuba Result: {karatsuba_result}")
    except ValueError as e:
        print(f"Test Case {i + 1}: {e}")
