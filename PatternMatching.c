#include <stdio.h>
#include <stdbool.h>

bool isMatch(char *s, char *p)
{
    if (*s == '\0' && *p == '\0')
    {
        return true; // Both strings are empty, match
    }
    else if (*p == '*' && *(p + 1) == '\0')
    {
        return true; // Pattern ends with *, match any remaining characters in s
    }
    else if (*p == '?' || *p == *s)
    {
        return isMatch(s + 1, p + 1); // Characters match or '?' matches any, continue comparison
    }
    else if (*p == '*')
    {
        // '*' can match multiple characters, try skipping characters in s
        return isMatch(s, p + 1) || isMatch(s + 1, p);
    }
    else
    {
        return false; // No match
    }
}

int main()
{
    char str[] = "geeksforgeeks";
    char pattern[] = "g*ks";

    if (isMatch(str, pattern))
    {
        printf("Pattern matches the string\n");
    }
    else
    {
        printf("Pattern does not match the string\n");
    }

    return 0;
}
