#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> //biblioteca para validacao da placa

typedef struct Veiculo{
    
    char Proprietario[40];
    char Combustivel[10];
    char Modelo[30];
    char Cor[40];
    int NumChassi;
    int Ano;
    char Placa[8];

    struct Veiculo *prox;
}Veiculo;

Veiculo* criarVeiculo(){ //criacao do veiculo
    Veiculo *novoVeiculo = (Veiculo*)malloc(sizeof(Veiculo));
    if(novoVeiculo == NULL){
        printf("\nMemoria insuficiente");
        exit(EXIT_FAILURE);
    }
    novoVeiculo->prox = NULL;
    return novoVeiculo;
}

Veiculo* cadastrar(Veiculo *lista){
    Veiculo *novoVeiculo = criarVeiculo();
    int combustivelValido = 0;
    int placaValida1 = 0;
    int placaValida2 = 0;
    int placaValida3 = 0;
    int i;
    
    printf("\nDigite o Proprietario: ");
    fgets(novoVeiculo->Proprietario, sizeof(novoVeiculo->Proprietario), stdin);
    fflush(stdin);

    do{
    printf("\nDigite o combustivel (Alcool, Gasolina ou Diesel): ");
    scanf("%s", novoVeiculo->Combustivel);

    if(strcmp(novoVeiculo->Combustivel, "Alcool") == 0 || strcmp(novoVeiculo->Combustivel, "Gasolina") == 0 || strcmp(novoVeiculo->Combustivel, "Diesel") == 0){
        combustivelValido = 1;
    } else {
        printf("\nCombustivel invalido, tente novamente");
    }
    fflush(stdin);
    } while(combustivelValido == 0);

    printf("\nDigite o Modelo: ");
    fgets(novoVeiculo->Modelo, sizeof(novoVeiculo->Modelo), stdin);
    fflush(stdin);

    printf("\nDigite a Cor: ");
    fgets(novoVeiculo->Cor, sizeof(novoVeiculo->Cor), stdin);
    fflush(stdin);

    printf("\nDigite o numero do Chassi: ");
    scanf("%d", &novoVeiculo->NumChassi);
    fflush(stdin);

    printf("\nDigite o ano: ");
    scanf("%d", &novoVeiculo->Ano);
    fflush(stdin);

    do{

    printf("\nDigite a Placa (letras maiusculas): ");
    scanf("%s", novoVeiculo->Placa);
    fflush(stdin);

    if(novoVeiculo->Placa[7] == '\0'){
        placaValida3 = 1;
    } else {
        placaValida3 = 0;
    }

    for(i = 0; i < 3; i++){
        if(isalpha(novoVeiculo->Placa[i])){
            placaValida1 = 1;
        } else {
            placaValida1 = 0;
            break;
        }
    }

    for(i = 3; i < 7; i++){
        if(isdigit(novoVeiculo->Placa[i])){
            placaValida2 = 1;
        } else {
            placaValida2 = 0;
            break;
        }
    }

    if(placaValida1 == 1 && placaValida2 == 1 && placaValida3 == 1){
        printf("Placa valida");
    } else {
        printf("Placa invalida, tente novamente");
        printf("\n");
    }
    } while (placaValida1 == 0 || placaValida2 == 0 || placaValida3 == 0);

    if(lista == NULL){
        return novoVeiculo;

    } else {
        Veiculo *atual = lista;

        while (atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = novoVeiculo;
        return lista;
    }
}

void mostrarTudo(Veiculo *lista){
    if(lista == NULL){
        printf("\n");
        printf("Lista NULA");
        printf("\n");
        return;
    } else {
        Veiculo *atual = lista;
        while (atual != NULL){
            printf("\n-----------------------------------------");
            printf("\nLista: ");
            printf("\n");
            printf("\nProprietario: %s", atual->Proprietario);
            printf("Combustivel: %s", atual->Combustivel);
            printf("\nModelo: %s", atual->Modelo);
            printf("Cor: %s", atual->Cor);
            printf("Numero do Chassi: %d", atual->NumChassi);
            printf("\nAno: %d", atual->Ano);
            printf("\nPlaca: %s", atual->Placa);
            printf("\n");
            printf("-----------------------------------------");
            printf("\n");
            atual = atual->prox;
        }
    }
}

void listar2010Diesel(Veiculo *lista){
    Veiculo *atual = lista;
    if(lista == NULL){
        printf("\n");
        printf("Lista NULA");
        printf("\n");
        return;
    } else {
            while (atual != NULL){

                if(atual->Ano >= 2010 && strcmp(atual->Combustivel, "Diesel") == 0){
                printf("\n-----------------------------------------");
                printf("\nLista: ");
                printf("\n");
                printf("\nProprietario: %s", atual->Proprietario);
                printf("Combustivel: %s", atual->Combustivel);
                printf("\nModelo: %s", atual->Modelo);
                printf("Cor: %s", atual->Cor);
                printf("Numero do Chassi: %d", atual->NumChassi);
                printf("\nAno: %d", atual->Ano);
                printf("\nPlaca: %s", atual->Placa);
                printf("\n");
                printf("-----------------------------------------");
                printf("\n");
                }

            atual = atual->prox;
            }
        }
    }

Veiculo* listarModeloCor(Veiculo *lista){
    Veiculo *atual = lista;

    if(lista == NULL){
        printf("\n");
        printf("Lista NULA");
        printf("\n");
        return;
    } else {
            while (atual != NULL){

                char segundaLetra = atual->Placa[1];
                int soma = (int)atual->Placa[3] + (int)atual->Placa[4] + (int)atual->Placa[5] + (int)atual->Placa[6];

                if((segundaLetra == 'A' || segundaLetra == 'E' || segundaLetra == 'I' || segundaLetra == 'O' || segundaLetra == 'U') && soma %2 == 0){
                    printf("\n-----------------------------------------");
                    printf("\nLista: ");
                    printf("\n");
                    printf("\nModelo: %s", atual->Modelo);
                    printf("Cor: %s", atual->Cor);
                    printf("-----------------------------------------");
                    printf("\n");
                }
            atual = atual->prox;
            }
        }
    }

Veiculo* listarPlaca(Veiculo *lista){
    Veiculo *atual = lista;

    if(lista == NULL){
        printf("\n");
        printf("Lista NULA");
        printf("\n");
        return;
    } else {
            while (atual != NULL){

                char primeiraLetra = atual->Placa[0];
                char ultimaLetra = atual->Placa[6];

                if(primeiraLetra == 'J' && (ultimaLetra == '0' || ultimaLetra == '2' || ultimaLetra == '4' || ultimaLetra == '7')){
                    printf("\n-----------------------------------------");
                    printf("\nLista: ");
                    printf("\n");
                    printf("\nPlaca: %s", atual->Placa);
                    printf("\nProprietario: %s", atual->Proprietario);
                    printf("-----------------------------------------");
                    printf("\n");
                }
            atual = atual->prox;
            }
        }
    }

Veiculo* buscarVeiculo(Veiculo *lista, int chassiBusca){
    if(lista == NULL){
        printf("\n");
        printf("Lista nula");
        printf("\n");
        return NULL;
    } else {
        Veiculo *atual = lista;
        while(atual != NULL){
            if(atual->NumChassi == chassiBusca){
            return atual;
            }
            atual = atual->prox;
        }
        printf("\nVeiculo nao encontrado");
        return NULL;
    }
}

void trocaProprietario(Veiculo *encontrada){
    printf("\nAlteracao do proprietario");
    fflush(stdin);
    printf("\nDigite o Proprietario: ");
    fgets(encontrada->Proprietario, sizeof(encontrada->Proprietario), stdin);
    fflush(stdin);

    printf("Alterado com sucesso");
    printf("\n");

}

main(){

    int opcao, chassiBusca;
    Veiculo *lista = NULL;
    Veiculo *encontrada;

    do{
        printf("\nDigite 1 para cadastrar.");
        printf("\nDigite 2 para listar todos os proprietarios cujos carros sao do ano de 2010 ou posterior e que sejam movidos a diesel.");
        printf("\nDigite 3 para listar todas as placas que comecem com a letra J e terminem com 0, 2, 4 ou 7 e seus respectivos proprietarios.");
        printf("\nDigite 4 para listar o modelo e a cor dos veiculos cujas placas possuem como segunda letra uma vogal e cuja soma dos valores fornece um numero par.");
        printf("\nDigite 5 para alterar o proprietario.");
        printf("\nDigite 6 para mostrar todas as informacoes de todos os carros.");
        printf("\nDigite 0 para sair.\n");
        scanf("%d", &opcao);
        fflush(stdin);

        switch(opcao){
            case 1:
                lista = cadastrar(lista);
            break;

            case 2:
                listar2010Diesel(lista);
            break;

            case 3:
                listarPlaca(lista);
            break;

            case 4:
                listarModeloCor(lista);
            break;

            case 5:
                printf("\nDigite o numero do chassi: ");
                scanf("%d", &chassiBusca);
                encontrada = buscarVeiculo(lista, chassiBusca);
                if(encontrada != NULL){
                    trocaProprietario(encontrada);
                }
            break;

            case 6:
                mostrarTudo(lista);
            break;

            case 0:
            break;
        }
    }while(opcao != 0);

}