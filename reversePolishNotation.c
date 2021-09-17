#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int pos = 0;
int posOp = 0;
int c = 0;
char exp[20];
char op[20];
char result[20];

void resultAppend(char *v, int i){
    result[pos] = v[i];
    pos++;
}

void opAppend(char *v, int i){
    op[posOp] = v[i];
    posOp++;
}

int main(){
//    Symbolic expressions   -------  Expected Results
//    (F*N)+(Y/W)            -------  FN*YW/+
//    (K*(O-V)/A             -------  KOV-*A/
//    A+B-H                  -------  ABH-+
    printf("\n Insert Expression: ");
    scanf("%s", &exp);

    for(int i=0; i<20; i++){
        c++;
        if(exp[i] == NULL){
            exp[i] = ')';
            break;
        }
    }

    for(int k = 0; k < c; k++){
            if(exp[k] == ')'){
                for(int i=posOp-1; i>=0; i--){
                    posOp--;
                    resultAppend(op, i);
                }
            } else if(exp[k] == '+' || exp[k] == '-' || exp[k] == '*' || exp[k] == '/'){
                opAppend(exp, k);
                posOp;
            }else{
                if(exp[k] != '('){
                    resultAppend(exp, k);
                }
            }
    }

    printf("\n ---- Result ---- \n");
    for(int i=0; i<10; i++){
        printf("%c", result[i]);
    }

}
