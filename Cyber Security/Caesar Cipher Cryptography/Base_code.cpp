#include <iostream>
#include <string>

using namespace std;

// Function to perform Caesar Cipher encryption
string encryptCaesarCipher(string plainText, int shift) {
    string cipherText = "";

    // Iterate through each character in the plain text
    for (char& ch : plainText) {
        // Encrypt only alphabetic characters
        if (isalpha(ch)) {
            // Determine the new character after shifting
            char shifted = (isupper(ch)) ? 'A' + (ch - 'A' + shift) % 26 : 'a' + (ch - 'a' + shift) % 26;
            cipherText += shifted;
        } else {
            // Non-alphabetic characters remain unchanged in the cipher text
            cipherText += ch;
        }
    }

    return cipherText;
}

// Function to decrypt Caesar Cipher text
string decryptCaesarCipher(string cipherText, int shift) {
    // Decrypting is essentially the same as encrypting but with a negative shift
    return encryptCaesarCipher(cipherText, 26 - shift); // 26 is the number of letters in the alphabet
}

int main() {
    string plainText = "Hello, World!";
    int shift = 3; // Example shift value

    // Encrypt the plain text
    string encryptedText = encryptCaesarCipher(plainText, shift);
    cout << "Encrypted text: " << encryptedText << endl;

    // Decrypt the cipher text
    string decryptedText = decryptCaesarCipher(encryptedText, shift);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
