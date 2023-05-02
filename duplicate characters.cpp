

#include <iostream>

void RemoveDups(char* str)
{
    
    int i = 0;
    int N = sizeof(str)+1;
    while (i !=N+1)
    {
        if (str[i] == str[i + 1])
        {
            for (int j = i; j != N; j++)
                str[j] = str[j + 1];
            str[N+1] = ' ';
            N--;
        }
        else i++;
    }

}

int main()
{
    char data[] = "AAA BBB AAA";
    RemoveDups(data);
    printf("%s\n", data);
}

// Соколенко Екатерина Романовна
// 26.04.2023 40 мин
