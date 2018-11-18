#include <string>
#include <iostream>
#include <cctype>
#include "error.h"

using namespace std;
bool endsWith(string str, string suffix);
string trim(string str);
string substr(string str, int pos, int n);
string capitalize(string str);
int scrabble(string word);
string acronym(string str);
string removeCharacters(string str, string remove);
bool isRemove(char ch, string remove);
void removeCharactersInPlace(string &str, string remove);
string removeDoubledLetters(string str);
string replaceAll(string str, char c1, char c2);
string replaceAll(string str, string s1, string s2);
bool isReplace(string str, string s1);
bool isSentencePalindrome(string str);
string reverse(string str);
string createRegularPlural(string word);
void createOrdinalForm(int n);
string addCommas(string digits);
string pigLatin(string str);
string wordToPigLatin(string word);
int findFirstVowel(string word);
bool isVowel(char ch);

int main()
{
    cout << pigLatin("This is Pig Latin.") << endl;
    return 0;
}

// 01
bool endsWith(string str, string suffix)
{
    if (str.length() < suffix.length())
        return false;

    for (int i = str.length() - suffix.length(), j = 0; i < str.length(); i++, j++)
    {
        if (str[i] != suffix[j])
            return false;
    }

    return true;
}

// 02
string trim(string str)
{
    if (str.length() < 2)
    {
        return str;
    }
    else
    {
        while (isspace(str[0]) && str.length() > 0)
        {
            str.erase(0, 1);
        }
        while (isspace(str[str.length() - 1]) && str.length() > 0)
        {
            str.erase(str.length() - 1, 1);
        }
    }

    return str;
}

// 03
string substr(string str, int pos, int n = -1)
{
    string result = "";
    int count;
    if (n == -1 || n > str.length() - (pos + 1))
    {
        count = str.length();
    }
    else
    {
        count = pos + n;
    }

    if (pos > str.length() - 1)
    {
        error("out of bounds");
    }

    for (int i = pos; i < count; i++)
    {
        result += str[i];
    }

    return result;
}

// 04
string capitalize(string str)
{
    str[0] = toupper(str[0]);

    for (int i = 1; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }

    return str;
}

// 05
int scrabble(string word)
{

    int points = 0;
    for (int i = 0; i < word.length(); i++)
    {

        switch (word[i])
        {
        case 'A':
        case 'E':
        case 'I':
        case 'L':
        case 'N':
        case 'O':
        case 'R':
        case 'S':
        case 'T':
        case 'U':
            points++;
            break;
        case 'D':
        case 'G':
            points += 2;
            break;
        case 'B':
        case 'C':
        case 'M':
        case 'P':
            points += 3;
            break;
        case 'F':
        case 'H':
        case 'V':
        case 'W':
        case 'Y':
            points += 4;
            break;
        case 'K':
            points += 5;
            break;
        case 'J':
        case 'X':
            points += 8;
            break;
        case 'Q':
        case 'Z':
            points += 10;
            break;
        default:
            break;
        }
    }
    return points;
}

// 06
string acronym(string str)
{
    string word = "";
    bool inWord = true;
    for (int i = 0; i < str.length(); i++)
    {
        if (inWord && isalpha(str[i]))
        {
            word += str[i];
            inWord = false;
        }
        else if (!isalpha(str[i]))
        {
            inWord = true;
        }
    }

    return word;
}

// 07
string removeCharacters(string str, string remove)
{
    string result = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (!isRemove(str[i], remove))
        {
            result += str[i];
        }
    }

    return result;
}
bool isRemove(char ch, string remove)
{
    for (int i = 0; i < remove.length(); i++)
    {
        if (remove[i] == ch)
            return true;
    }
    return false;
}

// 08
void removeCharactersInPlace(string &str, string remove)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (isRemove(str[i], remove))
        {
            str.erase(i, 1);
            i -= 1;
        }
    }
}

// 09
string removeDoubledLetters(string str)
{
    if (str.length() < 2)
    {
        return str;
    }
    char firstCh = str[0];
    char curCh;
    string result = "";
    result += firstCh;
    for (int i = 1; i < str.length(); i++)
    {
        curCh = str[i];
        if (firstCh != curCh)
        {
            result += curCh;
        }
        firstCh = curCh;
    }
    return result;
}

// 10
string replaceAll(string str, char c1, char c2)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c1)
        {
            str[i] = c2;
        }
    }

    return str;
}
string replaceAll(string str, string s1, string s2)
{
    if (str.length() < s1.length())
    {
        return str;
    }
    string result = "";
    for (int i = 0; i <= str.length() - s1.length(); i++)
    {
        if (str[i] == s1[0] && isReplace(str.substr(i, s1.length()), s1))
        {
            result += s2;
            i += s1.length() - 1;
        }
        else
        {
            result += str[i];
        }
    }
    return result;
}
bool isReplace(string str, string s1)
{
    return str == s1;
}

// 11
bool isSentencePalindrome(string str)
{
    string newStr = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (isalpha(str[i]))
        {
            newStr += tolower(str[i]);
        }
    }
    return newStr == reverse(newStr);
}

string reverse(string str)
{
    string newStr = "";
    for (int i = str.length() - 1; i >= 0; i--)
    {
        newStr += str[i];
    }

    return newStr;
}

// 12
string createRegularPlural(string word)
{

    if (word.length() < 2)
    {
        return word;
    }
    char lastOne = word[word.length() - 1];
    char lastTwo = word[word.length() - 2];
    switch (lastOne)
    {
    case 's':
    case 'S':
    case 'x':
    case 'X':
    case 'z':
    case 'Z':
        word.insert(word.length() - 1, "es");
        break;
    case 'h':
        if (lastTwo == 'c' || lastTwo == 's')
        {
            word.insert(word.length(), "es");
        }
        else
        {
            word.insert(word.length(), "s");
        }
        break;
    case 'y':
        word.replace(word.length() - 1, 1, "ies");
        break;
    default:
        word.insert(word.length(), "s");
        break;
    }

    return word;
}

// 13
void createOrdinalForm(int n)
{
    string suffix = "";
    int prefix = n % 100;
    if (prefix < 10 || prefix > 20)
    {
        switch (n % 10)
        {
        case 1:
            suffix = "st";
            break;

        case 2:
            suffix = "nd";
            break;
        case 3:
            suffix = "rd";
            break;
        default:
            suffix = "th";
            break;
        }
    }
    else
    {
        suffix = "th";
    }
    cout << n << suffix << endl;
}

// 14
string addCommas(string digits)
{
    string result = "";
    int count = 0;
    for (int i = digits.length() - 1; i >= 0; i--)
    {
        result = digits[i] + result;
        count++;

        if (count % 3 == 0 && i > 0)
        {
            result = "," + result;
        }
    }
    return result;
}

// 15
string pigLatin(string str)
{
    string word;
    string result;
    bool inWord = true;
    for (int i = 0; i < str.length(); i++)
    {
        if (isalpha(str[i]))
        {
            word += str[i];
        }
        else
        {
            result += wordToPigLatin(word);
            result += str[i];
            word = "";
        }
    }
    return result;
}

string wordToPigLatin(string word)
{
    bool capitalized = isupper(word[0]);
    for (int i = 0; i < word.length(); i++)
    {
        word[i] = tolower(word[i]);
    }
    int vp = findFirstVowel(word);
    if (vp == -1)
    {
        return word;
    }
    else if (vp == 0)
    {

        if (capitalized)
        {
            word[0] = toupper(word[0]);
        }
        return word + "way";
    }
    else
    {
        string head = word.substr(0, vp);
        string tail = word.substr(vp);
        if (capitalized)
        {
            tail[0] = toupper(tail[0]);
        }
        return tail + head + "ay";
    }
}

bool isVowel(char ch)
{
    switch (ch)
    {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}
int findFirstVowel(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (isVowel(word[i]))
            return i;
    }
    return -1;
}
