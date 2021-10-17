#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct{
    int codigo;
    char nome[40];
    char email[30];
}REGISTRO;

typedef struct{
    REGISTRO Elem[MAX];
    int topo; //posicao do elemento na pilha
} PILHA ;

void inicializarPilha(PILHA *p){
    p->topo = -1;
}

int estacheia(PILHA *p){

    if (p->topo >= MAX-1){
        printf("\nPILHA ESTA CHEIA!\n");
        return 1; //true
    }
    else
        return 0; //false
}

void push(PILHA *p){

    if (estacheia(p) != 1){
        REGISTRO pessoa;
        printf("Digite o codigo:");
        scanf("%d", &pessoa.codigo);
        printf("Digite o nome:");
        scanf("%s", &pessoa.nome);
        printf("Digite o e-mail:");
        scanf("%s", &pessoa.email);
        p->topo++;
        p->Elem[p->topo] = pessoa;
    }

}

int estavazia(PILHA *p){
    if (p->topo == -1){
        printf("\nPILHA VAZIA!\n");
        return 1;
    }
    else
        return 0;
}
void pop(PILHA *p){

    if (estavazia(p) != 1){
        printf("\n DESEMPILHANDO %d ", p->Elem[p->topo] );
        p->topo--;
    }
}
void exibir(PILHA *p){

    int i;
    REGISTRO elem_topo;

    if (estavazia(p) != 1){
        printf("\n\n IMPRESSAO \n");
        printf("CODIGO -       NOME       -       EMAIL: \n");
        for(i=p->topo; i>=0; i--){
            printf("%d    -       %s           %s \n", p->Elem[i].codigo,p->Elem[i].nome,p->Elem[i].email);
        }
        printf("\n");
        elem_topo = p->Elem[p->topo];
        printf("TOPO codigo: %d\n", elem_topo.codigo);
        printf("TOPO nome: %s\n", elem_topo.nome);
        printf("TOPO email: %s\n", elem_topo.email);
    }
}

int menu(){
    int opcao;

    printf("\n");
    printf("Escolha uma das opcoes: \n");
    printf("0. Sair\n");
    printf("1. Empilhar (PUSH)\n");
    printf("2. Desempilhar (POP)\n");
    printf("3. Exibir\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

void opcao(PILHA *p, int op){

    switch (op){
        case 0:
            exit(1);
        case 1: //empilhar
            push(p);
            break;
        case 2: //desempilhar
            pop(p);
            break;
        case 3: //desempilhar
            exibir(p);
            break;
        default: printf("\nOpcao Invalida\n");
    }
}

int main(){

    PILHA minhapilha;
    int op;

    inicializarPilha(&minhapilha);

    while (1){ // loop infinito
        op= menu();
        opcao(&minhapilha, op);
    }
    return 0;
}
