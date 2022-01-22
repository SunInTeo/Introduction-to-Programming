#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

void encode(char *str1, char *dist, char *str2, char *result)
{
    int encoding[128] = {0};

    for (int i = 0; i < strlen(str1) && i < strlen(dist); ++i)
    {
        if (encoding[str1[i]] != 0)
        {
            if (encoding[str1[i]] != dist[i])
            {
                strcpy(result, "");
                return;
            }
        }
        else
            encoding[str1[i]] = dist[i];
    }

    strcpy(result, str2);
    for (int i = 0; i < strlen(result); ++i)
    {
        if (encoding[result[i]] != 0)
        {
            result[i] = encoding[result[i]];
        }
    }
}

int main()
{
    // encode("hello","worrd","love",result) ще запише в result низа "rdvo"
    // r _ _ _

    // encode("hello","world","love",result) ще запише в result празния низ

    char result[128] = "";
    encode("hello", "worrd", "love", result);
    cout << "Result: " << result << endl;
    encode("hello", "world", "love", result);
    cout << "Result: " << result << endl;

    return 0;
}
