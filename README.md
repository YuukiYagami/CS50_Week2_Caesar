# CS50_Week2_Caesar

Solving Caesar from Harvard CS50
_____________________________________________________

Caesar is used to “encrypt” (i.e., conceal in a reversible way) confidential messages by shifting each letter therein by some number of places. For instance, he might write A as B, B as C, C as D, …, and, wrapping around alphabetically, Z as A. And so, to say HELLO to someone, Caesar might write IFMMP instead. Upon receiving such messages from Caesar, recipients would have to “decrypt” them by shifting letters in the opposite direction by the same number of places.

The secrecy of this “cryptosystem” relied on only Caesar and the recipients knowing a secret, the number of places by which Caesar had shifted his letters (e.g., 1).

Unencrypted text is generally called plaintext. Encrypted text is generally called ciphertext. And the secret used is called a key.

i.e Encrypting HELLO with a key of 1  yields IFMMP

Caesar’s algorithm (i.e., cipher) encrypts messages by “rotating” each letter by k positions. More formally, if p is some plaintext (i.e., an unencrypted message), pi is the character in ith character in p, and k is a secret key (i.e., a non-negative integer), then each letter, ci in the ciphertext, c is computed as

ci = ( pi + k ) % 26 

The following program enables user to encrypt messages using Caesar’s cipher. At the time the user executes the program, they should decide, by providing a command-line argument, what the key should be in the secret message they’ll provide at runtime. We shouldn’t necessarily assume that the user’s key is going to be a number; though you may assume that, if it is a number, it will be a positive integer.
