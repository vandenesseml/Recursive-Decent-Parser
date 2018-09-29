/*Max vandenesse
 *Assignment 3
 *9.27.2018
*/
#include <stdio.h>
#include <stdlib.h>

int index, validExpression, token;
char expression[100];
int main(int argc, char *argv[]) {
  FILE* file;
  if(argc > 1) {
  file=fopen(argv[1], "r");
} else {
  file=fopen("parserTokenizedInput.txt", "r");
}
token = 0;
while(fgets(expression, sizeof(expression), file)) {
  index = 0;
  validExpression = 1;
  Expression();
  int expressionSize = (strlen(expression));
  if (!expression[expressionSize]) {
    expressionSize = expressionSize-1;
  }
  token++;
  if(expressionSize != (index) || !validExpression) {
    printf("Token stirng %i invalid\n", token);
  }
}
printf("End Of File Reached\n");
close(file);
  return 0;
}

void Expression() {
  Term();
  Addition();
}

void Term() {
  Factor();
  Multiplication();
}

void Factor() {
  if(expression[index] == (char)40) {
      index++;
      int currentIndex = index;
      Expression();
      if ((expression[index]) == (char)41) {
        if(index != currentIndex){
          index++;
        } else {
          validExpression = 0;
        }
      } else {
        validExpression = 0;
      }
    } else {
      Number();
    }
}

void Number() {
  while (isdigit(expression[index])) {
    index++;
  }
}

void Addition() {
    if(expression[index] == (char)43) {
      if ((!isdigit(expression[index-1]) && ((expression[index-1]) != (char)41))) {
        validExpression = 0;
      }
      index++;
    Expression();
  }
}

void Multiplication() {
  if(expression[index] == (char)42){
    if ((!isdigit(expression[index-1]) && ((expression[index-1]) != (char)41))) {
      validExpression = 0;
    }
    index++;
    Term();
  }
}
