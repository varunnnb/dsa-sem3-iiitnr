<<<<<<< HEAD
#include <stdio.h>
#include <string.h>

int areAnagrams(char str1[], char str2[])
{
    int count[256] = {0};

    if (strlen(str1) != strlen(str2))
        return 0;

    for (int i = 0; str1[i] && str2[i]; i++)
    {
        count[(unsigned char)str1[i]]++;
        count[(unsigned char)str2[i]]--;
    }

    for (int i = 0; i < 256; i++)
    {
        if (count[i] != 0)
            return 0;
    }
    return 1;
}

int main()
{
    char str1[100], str2[100];

    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    if (areAnagrams(str1, str2))
        printf("Strings are Anagrams\n");
    else
        printf("Strings are Not Anagrams\n");

    return 0;
}
=======
#include <stdio.h>
#include <string.h>

int areAnagrams(char str1[], char str2[])
{
    int count[256] = {0};

    if (strlen(str1) != strlen(str2))
        return 0;

    for (int i = 0; str1[i] && str2[i]; i++)
    {
        count[(unsigned char)str1[i]]++;
        count[(unsigned char)str2[i]]--;
    }

    for (int i = 0; i < 256; i++)
    {
        if (count[i] != 0)
            return 0;
    }
    return 1;
}

int main()
{
    char str1[100], str2[100];

    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    if (areAnagrams(str1, str2))
        printf("Strings are Anagrams\n");
    else
        printf("Strings are Not Anagrams\n");

    return 0;
}
>>>>>>> 4c34cbbf97de81bf10cb98bbf1452083e678c8a0
