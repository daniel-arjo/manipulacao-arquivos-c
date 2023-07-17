#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

char livro1[20], livro2[20], livro3[20];
char autor1[20], autor2[20], autor3[20];

int ComparaString(const char *str1, const char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return (str1[i] - str2[i]);
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 0;
    }
    else {
        return (str1[i] - str2[i]);
    }
}

void Atualizar()
{
    FILE *arquivo;
    arquivo = fopen("livros.txt", "w");
    if(arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo, tente novamente!\n");
        exit(0);
    }

    fwrite(livro1, sizeof(livro1), 1, arquivo);
    fwrite(autor1, sizeof(autor1), 1, arquivo);
    fwrite(livro2, sizeof(livro2), 1, arquivo);
    fwrite(autor2, sizeof(autor2), 1, arquivo);
    fwrite(livro3, sizeof(livro3), 1, arquivo);
    fwrite(autor3, sizeof(autor3), 1, arquivo);
    fclose(arquivo);
}

void Receber()
{
    FILE *arquivo;
    arquivo = fopen("livros.txt", "r");
    if(arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo, tente novamente!\n");
        exit(0);
    }

    fread(&livro1, sizeof(livro1), 1, arquivo);
    fread(&autor1, sizeof(autor1), 1, arquivo);
    fread(&livro2, sizeof(livro2), 1, arquivo);
    fread(&autor2, sizeof(autor2), 1, arquivo);
    fread(&livro3, sizeof(livro3), 1, arquivo);
    fread(&autor3, sizeof(autor3), 1, arquivo);
    fclose(arquivo);
}

void EntraDados()
{
    int contLivros = 1, contAutores = 1;
    char confirmar;
    for (int i = 0; i < sizeof(livro1); i++)
        {
            livro1[i] = '\0';
            autor2[i] = '\0';
            livro2[i] = '\0';
            autor2[i] = '\0';
            livro3[i] = '\0';
            autor3[i] = '\0';
        }
    do
    {
        printf("Digite o nome do %i livro para gravar : \n", contLivros);
        getchar();
        gets(livro1);
        contLivros++;
        printf("Digite o nome do %i livro para gravar : \n", contLivros);
        gets(livro2);
        contLivros++;
        printf("Digite o nome do %i livro para gravar : \n", contLivros);
        gets(livro3);

        printf("Digite o nome do autor do livro %s: \n", livro1);
        gets(autor1);
        contAutores++;
        printf("Digite o nome do autor do livro %s: \n", livro2);
        gets(autor2);
        contAutores++;
        printf("Digite o nome do autor do livro %s: \n", livro3);
        gets(autor3);

        printf("Deseja confirmar o envio dos dados? : s/n\n");
        confirmar = getch();
        while(confirmar != 'n' && confirmar != 's' && confirmar != 'N' && confirmar != 'S')
        {
            printf("Entrada invalida, tente novamente : \n");
            printf("Deseja confirmar o envio dos dados? : s/n\n");
            confirmar = getch();
        }
        if(confirmar == 's' || confirmar == 'S')
        {
            Atualizar();
            printf("Dados enviados\n");
        }
        else{
            printf("Dados inalterados\n");
            break;
        }
    }
    while(confirmar == 'n' || confirmar == 'N');
}

void ListaDados()
{
    Receber();

    if(livro1[0]!='\0')
    {
        printf("%s de autoria %s\n", livro1, autor1);
    }
    else
    {
        printf("Nada para listar aqui\n");
    }
    if(livro2[0]!='\0')
    {
        printf("%s de autoria %s\n", livro2, autor2);
    }
    else
    {
        printf("Nada para listar aqui\n");
    }
    if(livro3[0]!='\0')
    {
        printf("%s de autoria %s\n", livro3, autor3);
    }
    else
    {
        printf("Nada para listar aqui\n");
    }
}

void PesquisarLivro(){
    char pesquisa[20];
    int existe1, existe2, existe3;

    printf("Digite o nome completo do livro para pesquisar: ");
    getchar();
    gets(pesquisa);
    Receber();
    existe1 = ComparaString(pesquisa, livro1);
    existe2 = ComparaString(pesquisa, livro2);
    existe3 = ComparaString(pesquisa, livro3);

    if(existe1 == 0){
        printf("Livro encontrado: %s de autoria %s\n", livro1, autor1);
    }
    else if(existe2 == 0){
        printf("Livro encontrado: %s de autoria %s\n", livro2, autor2);
    }
    else if(existe3 == 0){
        printf("Livro encontrado: %s de autoria %s\n", livro3, autor3);
    }
    else{
        printf("Nenhum livro com esse nome foi encontrado\n");
    }
}

void PesquisarAutor(){
    bool existe1 = false, existe2 = false, existe3 = false;
    char pesquisa;
    Receber();
    printf("Digite a primeira letra do nome do autor: ");
    scanf("%c", &pesquisa);
    scanf("%c", &pesquisa);

    if(pesquisa == autor1[0]){
        existe1 = true;
    }
    if(pesquisa == autor2[0]){
        existe2 = true;
    }
    if(pesquisa == autor3[0]){
        existe3 = true;
    }
    if(existe1 && existe2 && existe3){
        printf("Foram encontrados 3 autores iniciados com %c \n", pesquisa);
        printf("%s autor do livro: %s\n", autor1, livro1);
        printf("%s autor do livro: %s\n", autor2, livro2);
        printf("%s autor do livro: %s\n", autor3, livro3);
    }
    else if(existe1 && existe2){
        printf("Foram encontrados 2 autores iniciados com %c \n", pesquisa);
        printf("%s autor do livro: %s\n", autor1, livro1);
        printf("%s autor do livro: %s\n", autor2, livro2);
    }
    else if(existe1 && existe3){
        printf("Foram encontrados 2 autores iniciados com %c \n", pesquisa);
        printf("%s autor do livro: %s\n", autor1, livro1);
        printf("%s autor do livro: %s\n", autor3, livro3);
    }
    else if(existe2 && existe3){
        printf("Foram encontrados 2 autores iniciados com %c \n", pesquisa);
        printf("%s autor do livro: %s\n", autor2, livro2);
        printf("%s autor do livro: %s\n", autor3, livro3);
    }
    else if(existe1){
        printf("Foi encontrado 1 autor iniciado com %c \n", pesquisa);
        printf("%s autor do livro: %s\n", autor1, livro1);
    }
    else if(existe2){
        printf("Foi encontrado 1 autor iniciado com %c \n", pesquisa);
        printf("%s autor do livro: %s\n", autor2, livro2);
    }
    else if(existe3){
        printf("Foi encontrado 1 autor iniciado com %c \n", pesquisa);
        printf("%s autor do livro: %s\n", autor3, livro3);
    }
    else{
        printf("Nao foram encontrados autores comecados com essa letra\n");
    }

}

void AlterarDados()
{
    int existe1, existe2, existe3;
    char pesquisa[20];
    Receber();

    printf("Digite o nome completo do livro para pesquisar: ");
    getchar();
    gets(pesquisa);

    existe1 = ComparaString(pesquisa, livro1);
    existe2 = ComparaString(pesquisa, livro2);
    existe3 = ComparaString(pesquisa, livro3);

    if(existe1 == 0)
    {
        for (int i = 0; i < sizeof(livro1); i++)
        {
            livro1[i] = '\0';
            autor1[i] = '\0';
        }
        printf("Informe o novo livro: ");
        gets(livro1);
        printf("Informe o autor do novo livro: ");
        gets(autor1);
        printf("Atualizado com sucesso!\n");
    }

    else if(existe2 == 0)
    {
        for (int i = 0; i < sizeof(livro2); i++)
        {
            livro2[i] = '\0';
            autor2[i] = '\0';
        }
        printf("Informe o novo livro: ");
        gets(livro2);
        printf("Informe o autor do novo livro: ");
        gets(autor2);
        printf("Atualizado com sucesso!\n");
    }

    else if(existe3 == 0)
    {
        for (int i = 0; i < sizeof(livro3); i++)
        {
            livro3[i] = '\0';
            autor3[i] = '\0';
        }
        printf("Informe o novo livro: ");
        gets(livro3);
        printf("Informe o autor do novo livro: ");
        gets(autor3);
        printf("Atualizado com sucesso!\n");
    }

    else
    {
        printf("Nenhum livro foi encontrado\n");
        printf("Livros no catalogo : \n");
        ListaDados();
    }
    Atualizar();
}

void ExcluirDados()
{
    int existe1, existe2, existe3;
    char pesquisa[20];
    Receber();

    printf("Digite o nome completo do livro para pesquisar: ");
    getchar();
    gets(pesquisa);

    existe1 = ComparaString(pesquisa, livro1);
    existe2 = ComparaString(pesquisa, livro2);
    existe3 = ComparaString(pesquisa, livro3);

    if(existe1 == 0)
    {
        printf("Livro %s de autoria %s foi apagado\n", livro1, autor1);
        for (int i = 0; i < sizeof(livro1); i++)
        {
            livro1[i] = '\0';
            autor1[i] = '\0';
        }
    }
    else if(existe2 == 0)
    {
        printf("Livro %s de autoria %s foi apagado\n", livro2, autor2);
        for (int i = 0; i < sizeof(livro2); i++)
        {
            livro2[i] = '\0';
            autor2[i] = '\0';
        }
    }
    else if(existe3 == 0)
    {
        printf("Livro %s de autoria %s foi apagado\n", livro3, autor3);
        for (int i = 0; i < sizeof(livro3); i++)
        {
            livro3[i] = '\0';
            autor3[i] = '\0';
        }
    }
    else
    {
        printf("Nenhum livro foi encontrado\n");
        printf("Livros no catalogo : \n");
        ListaDados();
    }
    Atualizar();
}

int main()
{
    int opt;

    FILE *arquivo;
    arquivo = fopen("livros.txt", "r");
    if(arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo\n");
        printf("Se o mesmo nao existir, abra novamente o aplicativo e ele sera criado\n");
        arquivo = fopen("livros.txt", "w");
        exit(0);
    }
    fclose(arquivo);

    do{
    printf("----------------------------------------------------------------\n");
    printf("Aplicativo de Consulta de livros\n\n");
    printf("1 - Entrada de dados\n");
    printf("2 - Lista todos os dados na tela\n");
    printf("3 - Pesquisa um livro com o nome completo e mostra na tela\n");
    printf("4 - Pesquisa autor pela primeira letra e mostra todos na tela\n");
    printf("5 - Altera dados. Pesquisa pelo livro completo\n");
    printf("6 - Exclui dados. Pesquisa pelo livro completo\n");
    printf("7 - Saida\n");
    printf("Selecione uma das opcoes acima : ");
    scanf("%i", &opt);
    printf("----------------------------------------------------------------\n");

    switch(opt)
    {
    case 1:
        EntraDados();
        break;
    case 2:
        ListaDados();
        break;
    case 3:
        PesquisarLivro();
        break;
    case 4:
        PesquisarAutor();
        break;
    case 5:
        AlterarDados();
        break;
    case 6:
        ExcluirDados();
        break;
    case 7:
        printf("Finalizando...");
        break;
    default:
        printf("Opcao invalida! \n");
        break;
    }
    }while(opt != 7);
    return 0;
}
