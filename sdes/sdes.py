# Input the 10-bit key and 8-bit message
key = input("Enter 10 bit key: ")
message = input("Enter 8 bit message: ")

# Define permutation tables and S-boxes
p8_table = [6, 3, 7, 4, 8, 5, 10, 9]
p10_table = [3, 5, 2, 7, 4, 10, 1, 9, 8, 6]
p4_table = [2, 4, 3, 1]
IP = [2, 6, 3, 1, 4, 8, 5, 7]
IP_inv = [4, 1, 3, 5, 7, 2, 8, 6]
expansion = [4, 1, 2, 3, 2, 3, 4, 1]
s0 = [[1, 0, 3, 2], [3, 2, 1, 0], [0, 2, 1, 3], [3, 1, 3, 2]]
s1 = [[0, 1, 2, 3], [2, 0, 1, 3], [3, 0, 1, 0], [2, 1, 0, 3]]


# Define a function to apply a permutation table to the input
def apply_table(inp, table):
    res = ""
    for i in table:
        res += inp[i - 1]
    return res


# Define a function for left shifting a string
def left_shift(data):
    return data[1:] + data[0]


# Define a function for bitwise XOR of two strings
def xor(a, b):
    res = ""
    for i in range(len(a)):
        if a[i] == b[i]:
            res += "0"
        else:
            res += "1"
    return res


# Define a function to apply an S-box to a 2-bit input
def apply_sbox(s, data):
    row = int("0b" + data[0] + data[-1], 2)
    col = int("0b" + data[1:3], 2)
    return bin(s[row][col])[2:]


# Define the function for the Feistel function
def function(expansion, s0, s1, key, message):
    left = message[:4]
    right = message[4:]
    temp = apply_table(right, expansion)
    temp = xor(temp, key)
    l = apply_sbox(s0, temp[:4])
    r = apply_sbox(s1, temp[4:])
    l = "0" * (2 - len(l)) + l
    r = "0" * (2 - len(r)) + r
    temp = apply_table(l + r, p4_table)
    temp = xor(left, temp)
    return temp + right


# KEY GENERATION
# Apply the P10 permutation to the key
temp = apply_table(key, p10_table)
left = temp[:5]
right = temp[5:]
# Perform left shifts on the halves
left = left_shift(left)
right = left_shift(right)
# Generate the first subkey (key1) by applying P8
key1 = apply_table(left + right, p8_table)
left = left_shift(left)
right = left_shift(right)
left = left_shift(left)
right = left_shift(right)
# Generate the second subkey (key2) similarly
key2 = apply_table(left + right, p8_table)

# ENCRYPTION
# Apply the initial permutation (IP) to the message
temp = apply_table(message, IP)
# Perform the Feistel function with key1
temp = function(expansion, s0, s1, key1, temp)
# Swap the halves and perform the Feistel function with key2
temp = temp[4:] + temp[:4]
temp = function(expansion, s0, s1, key2, temp)
# Apply the inverse permutation (IP_inv) and print the ciphertext
CT = apply_table(temp, IP_inv)
print("Cipher text is:", CT)
