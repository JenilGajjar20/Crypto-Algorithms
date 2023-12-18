# Crypto-Algorithms

Welcome to Crypto-Algorithms, a repository containing various cryptographic algorithms implemented in **Cpp** and **Python**. This collection aims to provide clear and well-documented implementations of fundamental cryptographic techniques.

## Table of Contents

- [Introduction](#introduction)
- [Algorithms](#algorithms)
  - [Symmetric Key Algorithms](#symmetric-key-algorithms)
    - [RC4](#rc4)
    - [SDES (Simplified Data Encryption Standard)](#sdes)
    - [Ciphers](#ciphers)
      - [Caesar](#caesar)
      - [Playfair](#playfair)
      - [Transposition](#transposition)
      - [Railfence](#railfence)
      - [Affine](#affine)
  - [Asymmetric Key Algorithms](#asymmetric-key-algorithms)
    - [RSA (Rivest–Shamir–Adleman)](#rsa)
    - [Elgamal Digital Signature](#elgamal-digital-signature)
  - [Number Theory](#number-theory)
    - [Chinese Remainder Theorem](#chinese-remainder-theorem)
    - [Pseudo Random Number Generation](#pseudo-random-number-generation)
      - [Euclidean Algorithm](#euclidean-algorithm)
      - [Extended Euclidean Algorithm](#extended-euclidean-algorithm)
  - [Networking](#networking)
    - [Socket Programming](#socket-programming)

## Introduction

This repository is a collection of cryptographic algorithms and related utilities implemented in **Cpp** and **Python**. Whether you're a student learning about cryptography or a developer seeking reliable implementations for your projects, Crypto-Algorithms offers a diverse set of algorithms.

## Algorithms

### Symmetric Key Algorithms

- RC4: It is a widely used symmetric key algorithm for stream ciphers.
- SDES: It is a basic form of the Data Encryption Standard (DES).

#### Ciphers

- Caesar: It is a classic substitution cipher where each letter in the plaintext is shifted by a certain number of places down or up the alphabet.
- Playfair: It is a digraph substitution cipher that encrypts pairs of letters, providing a more secure alternative to simple ciphers like Caesar.
- Transposition: It involves rearranging the letters of the plaintext to create the ciphertext.
- Railfence: It is a type of transposition cipher where the text is written in zigzag lines on a predefined number of rails.
- Affine: It is a type of monoalphabetic substitution cipher where each letter in the plaintext is mapped to its numeric equivalent, transformed, and then converted back to a letter.

### Asymmetric Key Algorithms

- RSA: It is a widely used asymmetric key algorithm for secure data transmission.

### Digital Signature

- Elgamal: It is an algorithm for creating digital signatures that can be used to verify the authenticity of a message.

### Number Theory

- Chinese Remainder Theorem: It is a number theory algorithm that provides a solution to a system of simultaneous linear congruences.
- Pseudo Random Number Generation: It includes implementations of algorithms for generating pseudo-random numbers, including the Euclidean and Extended Euclidean algorithms.
  - Euclidean Algorithm: It is used for finding the greatest common divisor (GCD) of two numbers.
  - Extended Euclidean Algorithm: It is an extension of the Euclidean Algorithm used for finding integers x and y such that ax + by = gcd(a, b).

### Networking

- Socket Programming: It includes examples and utilities for network programming, showcasing practical applications of cryptographic algorithms.

## Contributing

Contributions are welcome! If you find any issues, have suggestions, or want to add new algorithms, please feel free to open an issue or submit a pull request.

Happy coding! 🚀
