#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::nothrow;

void read_str(char *str, int size)
{
    str[0] = '\0';
    char *tmp = new (nothrow) char[size + 1];
    if (!tmp)
    {
        cout << "Invalid memory!" << endl;
        return;
    }

    while (strlen(str) < size)
    {
        if (str[0] != '\0')
        { 
            int n = strlen(str);
            str[n] = '\n';
            str[n + 1] = '\0';
        }
        cin.getline(tmp, size);
        strcat(str, tmp);
    }

    delete[] tmp;
}

bool is_letter(char x)
{
    return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

char *get_word(const char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (!is_letter(str[i]))
        { // end of word
            char *word = new (nothrow) char[i + 1];
            if (!word)
            {
                cout << "Invalid memory!" << endl;
                return nullptr;
            }

            strncpy(word, str, i);
            return word;
        }
    }
}

void add_element(char *word, char **&tokens, int &tokens_cnt)
{
    char **tmp = new (nothrow) char *[tokens_cnt + 1];
    if (!tmp)
    {
        cout << "Invalid memory!" << endl;
        return;
    }

    for (int i = 0; i < tokens_cnt; i++)
    {
        tmp[i] = tokens[i];
    }
    tmp[tokens_cnt] = word;
    tokens_cnt++;

    delete[] tokens;
    tokens = tmp;
}

char **tokenize(const char *str, int &tokens_cnt)
{
    tokens_cnt = 0;
    char **tokens = nullptr;

    int index = 0;
    while (index < strlen(str))
    {
        if (is_letter(str[index]))
        {
            char *word = get_word(str + index);
            add_element(word, tokens, tokens_cnt);
            index += strlen(word);
        }
        index++;
    }

    return tokens;
}

int main()
{
    int n;
    cin >> n;
    char *str = new (nothrow) char[n + 1];
    if (!str)
    {
        cout << "Invalid memory!" << endl;
        return 1;
    }
    cin.ignore();
    read_str(str, n);

    int m;
    char **tokens = tokenize(str, m);

    for (int i = 0; i < m; i++)
    {
        cout << tokens[i] << endl;
    }

    for (int i = 0; i < m; i++)
    {
        delete[] tokens[i];
    }
    delete[] tokens;

    delete[] str;

    return 0;
}

/*
16
Absd23 gkd
hjds.
*/