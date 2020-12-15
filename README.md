# XOR-encrypting

I have made my first encrypting algorithm on C++ using XOR.

You can build my project using g++ in Linux or other compilator (works on Windows)

# Building
Encryptor:
g++ encrypt.cpp -o encrypt 

Decryptor:
g++ decrypt.cpp -o decrypt 

# Using
Example: ./encrypt -f source_file.txt -k key -o encrypted_file.txt

To use encryptor/decryptor you need specify 3 obligatory parameters:

  -f - File to encrypt/decrypt
  
  -k - Key used for encrypting file (it is better to use a numeric key)
  
  -o - Output file with encrypted/decrypted text or file 
  
  --binary - Makes it possible to encrypt/decrypt binary files like images, executeable files, etc.
  
  Update 13 Dec 2020 23:57 - If you specify "@" as output file name the result of encryption/decryption will be printed in console.
