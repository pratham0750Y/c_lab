#include <string.h>
char stack[51];
int top=-1,score=0;

void pop()
{
    top--;

}
void push()
{
    stack[++top]='(';
}

int scoreOfParentheses(char* s) {
    top=-1;
    score=0;
    for(int i=0;i<strlen(s);i++)
    if(s[i]=='(')
        push();
    else
        pop();
    
    return score;
}