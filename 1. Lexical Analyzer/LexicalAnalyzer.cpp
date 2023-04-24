#include <bits/stdc++.h>
using namespace std;

bool isPunctuator(char ch)					//check if the given character is a punctuator or not
{
    char punctuator[] = " +-*/,;><=()[]{}&|";
    for(int i = 0; i < 18; ++i){
        if(ch == punctuator[i])
        {
            return true;
        }
    }
    return false;
}

bool validIdentifier(char* str)						//check if the given identifier is valid or not
{
    if (isdigit(str[0]) || isPunctuator(str[0]) == true)
        {
            return false;
        }									//if first character of string is a digit or a special character, identifier is not valid
    int i,len = strlen(str);
    if (len == 1)
    {
        return true;
    }										//if length is one, validation is already completed, hence return true
    else
    {
    for (i = 1 ; i < len ; i++)						//identifier cannot contain special characters
    {
        if (isPunctuator(str[i]) == true)
        {
            return false;
        }
    }
    }
    return true;
}

bool isOperator(char ch)							//check if the given character is an operator or not
{
    char operators[] = "+-*/%=";
    for(int i = 0; i < 6; ++i){
        if(ch == operators[i])
        {
            return true;
        }
    }
    return false;
}

bool isKeyword(char *str)						//check if the given substring is a keyword or not
{
    char keywords[32][10] =
    {"auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while"};
    int i;
    for(i = 0; i < 32; ++i)
    {
        if(strcmp(keywords[i], str) == 0)
        {
            return true;
        }
    }
    return false;
}

bool isNumber(char* str)							//check if the given substring is a number or not
{
    int i, len = strlen(str),numOfDecimal = 0;
    if (len == 0)
    {
        return false;
    }
    for (i = 0 ; i < len ; i++)
    {
        if (numOfDecimal > 1 && str[i] == '.')
        {
            return false;
        } else if (numOfDecimal <= 1)
        {
            numOfDecimal++;
        }
        if (!isdigit(str[i]) || (str[i] == '-' && i > 0))
            {
                return false;
            }
    }
    return true;
}

char* subString(char* realStr, int l, int r)				//extract the required substring from the main string
{
    int i;

    char* str = (char*) malloc(sizeof(char) * (r - l + 2));

    for (i = l; i <= r; i++)
    {
        str[i - l] = realStr[i];
        str[r - l + 1] = '\0';
    }
    return str;
}


void parse(char* str)						//parse the expression
{
    int left = 0, right = 0;
    int len = strlen(str);
    while (right <= len && left <= right) {
        if (isPunctuator(str[right]) == false)			//if character is a digit or an alphabet
            {
                right++;
            }

        if (isPunctuator(str[right]) == true && left == right)		//if character is a punctuator
            {
            if (isOperator(str[right]) == true)
            {
                cout<< str[right] <<" : OPERATOR\n";
            }
            right++;
            left = right;
            } else if (isPunctuator(str[right]) == true && left != right
                   || (right == len && left != right)) 			//check if parsed substring is a keyword or identifier or number
            {
            char* sub = subString(str, left, right - 1);   //extract substring

            if (isKeyword(sub) == true)
                        {
                            cout<< sub <<" : KEYWORD\n";
                        }
            else if (isNumber(sub) == true)
                        {
                            cout<< sub <<" : NUMBER\n";
                        }
            else if (validIdentifier(sub) == true
                     && isPunctuator(str[right - 1]) == false)
                     {
                         cout<< sub <<" : VALID IDENTIFIER\n";
                     }
            else if (validIdentifier(sub) == false
                     && isPunctuator(str[right - 1]) == false)
                     {
                         cout<< sub <<" : INVALID IDENTIFIER\n";
                     }

            left = right;
            }
    }
    return;
}

int main()
{
    char c[100] = "int m = n + 3p * 4";
    parse(c);
    return 0;
}
