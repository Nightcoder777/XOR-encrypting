# XOR-encrypting

I have made my first encrypting algorithm on C++ using XOR.

You can build my project using g++ in Linux or other compilator (works on Windows)

==========BUILDING==========

Encryptor:
g++ encrypt.cpp -o encrypt 

Decryptor:
g++ decrypt.cpp -o decrypt 

=============================


==================================USING=================================

Example: ./encrypt -f text_to_encrypt.txt -k key -o encrypted_text.txt

To use encryptor/decryptor you need specify 3 parameters:
-f - File with text to encrypt
-k - Key used for encrypting text (it is better to use a numeric key)
-o - Output file with encrypted text

=========================================================================
