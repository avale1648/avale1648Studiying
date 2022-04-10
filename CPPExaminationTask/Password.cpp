#include "Password.h"

string Password::encrypt() const
{
    string crypted;
    for (int i = 0; i < password.size(); i++)
        crypted += password[i] ^ 2;
    return crypted;
}

void Password::decrypt()
{
    string decrypted;
    for (int i = 0; i < password.size(); i++)
        decrypted += password[i] ^ 2;
    password = decrypted;
}
