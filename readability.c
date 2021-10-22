#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int number_of_letters(string letters);

int number_of_words(string words);

int number_of_sentences(string sentences);

int main(void)
{
    string text = get_string("Text: ");
    int nletters = number_of_letters(text);
    int nwords = number_of_words(text);
    int nsentences = number_of_sentences(text);
    int index = 0;
    float S = 100 * ((float) nsentences / nwords);
    float L = 100 * ((float) nletters / nwords);
    index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
       printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
       printf("Grade 16+\n");
    }
    else
    {
      printf("Grade %i\n", index);
    }

}

//fuction to count numbers of letters
int number_of_letters(string letters)
{
    int nletters = 0;
    for (int i = 0, l = strlen(letters); i < l; i++)
    {
        //that function verify if the char is a letters or not
        if (isalpha(letters[i]))
        {
            nletters = nletters + 1;
        }
    }
    return nletters;
}

//function to count number of words
int number_of_words(string words)
{
    int nwords = 0; //number of words is number of spaces-1
    int wspaces = 0;//get the number of character
    for (int i = 0, len = strlen(words); i < len ; i++)
    {
        if (isspace(words[i]))
        {
            wspaces = wspaces + 1;
        }
    }
    nwords = wspaces + 1;
    return nwords;
}

//function to calculate number of sentences
int number_of_sentences(string sentences)
{
    int nsentences = 0;//used to count . ! ? and it equal to number of sentences
    for (int i = 0, len = strlen(sentences); i < len; i++)
    {
        if (sentences[i] == '.' || sentences[i] == '!' || sentences[i] == '?')
        {
            nsentences = nsentences + 1;
        }
    }
    return nsentences;

}