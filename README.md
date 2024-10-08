# Cryptography Algorithms

This repository contains implementations of classic cryptography algorithms using C++. These algorithms showcase the fundamentals of encryption and key exchange mechanisms used in secure communication. Below is a description of the algorithms included:

# 1. Playfair Cipher

The Playfair Cipher is a digraph substitution cipher, where pairs of letters are encrypted instead of single letters. The cipher uses a 5x5 matrix of letters constructed using a keyword. It is one of the most well-known manual symmetric encryption techniques.

# Key Features:

- Builds a cipher matrix from a keyword.
- Encrypts and decrypts text based on digraphs (pairs of letters).
- Replaces repeated letters with 'x' if they appear in the same digraph.

# 2. RSA Algorithm

RSA is an asymmetric encryption algorithm used for secure data transmission. It leverages two keys: a public key for encryption and a private key for decryption. RSA is widely used in securing sensitive data, especially in online communication.

# Key Features:

- Generates public and private keys using large prime numbers.
- Encrypts messages with the public key and decrypts with the private key.
- Demonstrates encryption and decryption of string messages.

# 3. Diffie-Hellman Key Exchange

The Diffie-Hellman algorithm allows two parties to securely exchange cryptographic keys over a public channel. This key exchange is crucial in establishing a secure communication channel without the need for prior sharing of secret keys.

# Key Features:

- Generates a shared secret key between two parties.
- Uses modular arithmetic and primitive roots.
- Prevents eavesdroppers from accessing the exchanged key, even when the communication occurs over a public medium.

# 4. Hill Cipher
The Hill Cipher is a polygraphic substitution cipher that operates on blocks of letters using matrix multiplication. It encrypts plaintext letters by converting them into numerical vectors, then multiplying them by an invertible matrix to produce ciphertext.

# Key Features:

- Encrypts messages using matrix multiplication.
- Demonstrates both encryption and decryption processes.
- Highlights the importance of using invertible matrices for decryption.

# 5. Extended Euclidean Algorithm (GCD Calculation)
The Extended Euclidean Algorithm is used to find the greatest common divisor (GCD) of two numbers. It is often used in cryptography for calculating the modular multiplicative inverse, which is essential for algorithms like RSA.

# Key Features:

- Computes GCD of two integers.
- Finds the modular inverse, a key step in RSA encryption.

# How to Use
```bash
1. Clone the repository:
   git clone <repository_url>
2. Compile and run any algorithm:
   g++ <algorithm>.cpp -o <output-file>
./<output-file>
```

Each file contains the relevant code for the algorithm. You can run the code to see how each encryption method works in practice.