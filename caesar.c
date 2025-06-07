#include <cs50.h>
#include <ctype.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototype
bool check(string temp_str);
char rotate(char c, int k);

int main(int argc, string argv[])
{
    // Variable for key
    int key = 0;
    string plaintext;

    char temp_char;
    int n;

    // if argument count is not 2
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");

        return 1;
    }

    // if argument count is 2, checking if argv is contains all digit by calling check function.
    else
    {
        // if check comes false , print input format
        if (check(argv[1]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

        // if check comes true, convert argv[1] into key and ask for plaintext
        else
        {
            key = atoi(argv[1]);
            plaintext = get_string("plaintext: ");
        }
    }

    // Getting plaintext lenght
    n = strlen(plaintext);
    printf("ciphertext: ");
    for (int i = 0; i < n; i++)
    {
        // calling rotate function to iterate each char and add key to it and then printing
        temp_char = rotate(plaintext[i], key);
        printf("%c", temp_char);
    }
    printf("\n");
}

// Defining check function
bool check(string temp_str)
{
    // declaring a bool check, temp c char and n for str lenght
    char c;
    bool check = 0;
    int n = strlen(temp_str);

    // looping through every character in string
    for (int i = 0; i < n; i++)
    {
        c = temp_str[i];

        // checking if each character in string is not a digit
        if (!isdigit(c))
        {
            // check becomes false immediately if it detects alpha or spaces or anything non numeric
            // and breaks loops
            check = 0;
            break;
        }
        else
        {
            // check remains true and loop continues
            check = 1;
        }
    }
    return check;
}

// Defining rotate function
char rotate(char c, int k)
{
    // Initializing temporary variables
    char temp;
    int a;

    // Checking if its not a alphabet, print the character as is
    if (!isalpha(c))
    {
        temp = c;
    }
    else
    {
        // Checking if character is uppercase
        // Converting c to the position of the character in the alphabet (0 for 'A') and then
        // applying formula
        if (isupper(c))
        {
            a = c - 'A';
            temp = (char) 'A' + (a + k) % 26;
        }
        else
        {
            a = c - 'a';
            temp = (char) 'a' + (a + k) % 26;
        }
    }
    return temp;
}
