int add(const char* input)
{
    int sum = 0, i = 0, j = 0;
    char String[10] = {0};
    for(i = 0; i < strlen(input); i++)
    {
        if((input[i] >= 48) && (input[i] <= 57))
        {
            String[j++] = input[i];
        }
        else if((input[i] == 45) && (input[i+1] >= 48) && (input[i+1] <= 57))
        {
            printf("Exception: negatives not allowed:%c%c\n", input[i], input[i+1]);
            exit(1);
        }
        else
        {
            sum += atoi(String) > 1000 ? 0: atoi(String);
            memset(String, 0, 10);
            j = 0;
        }
    }
    return sum += atoi(String) > 1000 ? 0: atoi(String);
}
