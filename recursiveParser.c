/*Max vandenesse
 *Assignment 3
 *9.27.2018
*/
#include <stdio.h>
#include <stdlib.h>

int index, validExpression;
char expression[100];
int main(int argc, char *argv[]) {
  FILE* file;
  if(argc > 1) {
  file=fopen(argv[1], "r");
} else {
  file=fopen("parserTokenizedInput.txt", "r");
}

while(fgets(expression, sizeof(expression), file)) {
  index = 0;
  validExpression = 1;
  Expression();
  int expressionSize = (strlen(expression));
  if (!expression[expressionSize]) {
    expressionSize = expressionSize-1;
  }
  if(expressionSize == (index) && validExpression) {
    printf("\n%sValid\n\n", expression);
  } else{
    printf("\n%sInvalid\n\n", expression);
  }
}
close(file);
  return 0;
}

void Expression() {
  printf("(*E index: %i)\n", index);
  Term();
  Addition();
}

void Term() {
  printf("(*T index: %i)\n", index);
  Factor();
  Multiplication();
}

void Factor() {
  printf("(*F index: %i)\n", index);
  if(expression[index] == (char)40) {
    printf("(*Lparen index: %i)\n\n", index);
      index++;
      int currentIndex = index;
      Expression();
      if ((expression[index]) == (char)41) {
        if(index != currentIndex){
          printf("(*Rparen index: %i token %i)\n\n", index, expression[index]);
          index++;
        } else {
          printf("(*invalid Rparen index: %i token %i)\n\n", index, expression[index]);
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
  printf("(*num index: %i)\n", index);
  while (isdigit(expression[index])) {
    printf("(**num index: %i)\n\n", index);
    index++;
  }
}

  void Addition() {
    printf("(*add index: %i)\n", index);
      if(expression[index] == (char)43) {
        if ((!isdigit(expression[index-1]) && ((expression[index-1]) != (char)41))) {
  validExpression = 0;
}
        printf("(**add index: %i)\n\n", index);
        index++;

      Expression();
    }

  }

  void Multiplication() {
    printf("(*mult index: %i)\n", index);
    if(expression[index] == (char)42){
      if ((!isdigit(expression[index-1]) && ((expression[index-1]) != (char)41))) {
  validExpression = 0;
}
      printf("(**mult index: %i)\n\n", index);
      index++;
      Term();
    }

  }
