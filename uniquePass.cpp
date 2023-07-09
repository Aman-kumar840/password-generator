#include <bits/stdc++.h>
using namespace std;

// Function to generate a random password
string generatePassword(int length, bool includeUppercase, bool includeLowercase, bool includeNumbers, bool includeSpecialChars)
{
    // Define character sets based on user input
    string uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
    string numberChars = "0123456789";
    string specialChars = "!@#$%^&*()_+{}[]<>?";

    // Create a string to store the possible characters based on user input
    string possibleChars = "";
    if (includeUppercase)
        possibleChars += uppercaseChars;
    if (includeLowercase)
        possibleChars += lowercaseChars;
    if (includeNumbers)
        possibleChars += numberChars;
    if (includeSpecialChars)
        possibleChars += specialChars;

    // Use a random device to generate random numbers
    random_device rd;
    mt19937 generator(rd());

    // Shuffle the possible characters
    shuffle(possibleChars.begin(), possibleChars.end(), generator);

    // Create the password by selecting random characters from the shuffled set
    string password = "";
    for (int i = 0; i < length; ++i)
    {
        password += possibleChars[generator() % possibleChars.size()];
    }

    return password;
}

int main()
{
    // Get user input for password criteria
    int length;
    bool includeUppercase, includeLowercase, includeNumbers, includeSpecialChars;
    cout << "Enter the desired length of the password: ";
    cin >> length;
    cout << "Include uppercase letters (1 for yes, 0 for no): ";
    cin >> includeUppercase;
    cout << "Include lowercase letters (1 for yes, 0 for no): ";
    cin >> includeLowercase;
    cout << "Include numbers (1 for yes, 0 for no): ";
    cin >> includeNumbers;
    cout << "Include special characters (1 for yes, 0 for no): ";
    cin >> includeSpecialChars;
    int t = 4;
    while (t--)
    { // Generate the password
        string password = generatePassword(length, includeUppercase, includeLowercase, includeNumbers, includeSpecialChars);

        // Print the generated password
        cout << "Generated Password " << 4 - t << ": " << password << endl;
    }

    return 0;
}
