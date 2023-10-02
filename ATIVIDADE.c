#include <stdio.h>
#include <string.h>
#define ARQUIVO "filmes.txt"



#define MAX_STRING 100
#define MAX_FILMES 5


typedef struct
{
    char titulo[MAX_STRING];
    char diretor[MAX_STRING];
    int anoLancamento;
    float classificacao;
    int quantidade;

} Filme;


Filme cadastrarFilme();
void mostrarFilmes();
void exibirFilme(int i);
void buscarFilme(char *nome);
void buscarDiretor(char *diretor);
void alugarFilme (char *nome);
void excluirFilme(char *nome);
void devoluçãoFilme(char *nome);
void salvarFilmes();
void carregarFilmes();


Filme filmes[MAX_FILMES];
int totalFilmes = 0;


int main()
{

    carregarFilmes();
    
    int opcao;
    char nomeFilme[MAX_STRING];
    char nomeDiretor[MAX_STRING];

    do
    {


        printf("\nLocadora de Filmes\n");
        printf("1. Cadastrar Filme\n");
        printf("2. Ver Filmes Cadastrados\n");
        printf("3. Buscar Filme Por Nome\n");
        printf("4. Buscar Filme Por Diretor\n");
        printf("5. Alugar Filme\n");
        printf("6. Devolver Filme\n");
        printf("7. Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if (totalFilmes < MAX_FILMES)
            {
                filmes[totalFilmes] = cadastrarFilme();
                totalFilmes++;
                salvarFilmes();
            }
            else
            {
                printf("Quantidade máxima de filmes cadastrada");
            }
            break;


        case 2:
            mostrarFilmes();
            break;


        case 3:
            printf("\nInforme o nome do filme: ");
                getchar(); 
                fgets(nomeFilme, MAX_STRING, stdin);
                nomeFilme[strcspn(nomeFilme, "\n")] = '\0';

                buscarFilme(nomeFilme);

                excluirFilme(nomeFilme);
                salvarFilmes();
                
                break;
        

        case 4:
            printf("\nInforme o nome do diretor: ");
                getchar(); 
                fgets(nomeDiretor, MAX_STRING, stdin);
                nomeDiretor[strcspn(nomeDiretor, "\n")] = '\0';

                buscarDiretor(nomeDiretor);

                break;

        case 5:
            printf("\nInforme o nome do filme: ");
                getchar(); 
                fgets(nomeFilme, MAX_STRING, stdin);
                nomeFilme[strcspn(nomeFilme, "\n")] = '\0';

                    alugarFilme(nomeFilme);
                    salvarFilmes();

                    break;

        case 6:
            printf("\nInforme o nome do filme: ");
                getchar(); 
                fgets(nomeFilme, MAX_STRING, stdin);
                nomeFilme[strcspn(nomeFilme, "\n")] = '\0';

                    devoluçãoFilme(nomeFilme);
                    salvarFilmes();

                    break;


        case 7:
        return 0;

        default:
            printf("\nOpção inválida!\n");
        }

    } while (opcao != 7);

    return 0;
}



Filme cadastrarFilme()
{
    Filme f;
    getchar();

    printf("\n--- Cadastro de Filme ---\n");
    printf("Informe o título do filme: ");
    fgets(f.titulo, MAX_STRING, stdin);
    f.titulo[strcspn(f.titulo, "\n")] = '\0';

    printf("Informe o diretor do filme: ");
    fgets(f.diretor, MAX_STRING, stdin);
    f.diretor[strcspn(f.diretor, "\n")] = '\0';

    printf("Informe o ano de lançamento do filme: ");
    scanf("%d", &f.anoLancamento);

    printf("Informe a classificação do filme (0.0 a 10.0): ");
    scanf("%f", &f.classificacao);

    printf("Informe a quantidade de cópias em estoque: ");
    scanf("%d", &f.quantidade);

    return f;
}

void exibirFilme(int i)
{
    Filme f = filmes[i];
    printf("\nTítulo: %s\n", f.titulo);
    printf("Diretor: %s\n", f.diretor);
    printf("Ano de Lançamento: %d\n", f.anoLancamento);
    printf("Classificação: %.1f\n", f.classificacao);
    printf("Quantidade em estoque: %d\n", f.quantidade);
    printf("INDEX %d\n", i);
}

void mostrarFilmes()
{
    printf("\n--- Lista de Filmes ---\n");

    if (totalFilmes == 0)
    {
        printf("Nenhum filme cadastrado!\n");
    }
    else
    {
        for (int i = 0; i < totalFilmes; i++)
        {
            exibirFilme(i);
        }
    }
}

void buscarFilme(char *nome)
{
    int match = 0;
    int otp;
    for (int i = 0; i < totalFilmes; i++) 
        {
            if (strcmp(filmes[i].titulo, nome) == 0) 
            {
                exibirFilme(i);
                match++;

                printf("Deseja excluir o filme?\nSIM-digite 1\nNAO-digite 2");

                scanf ("%d", &otp);
                    if (otp==2)
                    {
                        break;
                    }

            }
        }
        if (match == 0)
        {
            printf ("\nFilme Nao Encontrado!");
        }
}

void buscarDiretor(char *diretor)
{
    int match = 0;
    printf ("Fimes por %s:\n", diretor);

    for (int i = 0; i < totalFilmes; i++) 
        {
            if (strcmp(filmes[i].diretor, diretor) == 0) 
            {
                exibirFilme(i);
                match++;
            }
        }

        if (match == 0)
        {
            printf ("\nDiretor Nao Encontrado!");
        }
}

void alugarFilme (char *nome)
{
    
    for (int i = 0; i < totalFilmes; i++) 
    {
        if (strcmp(filmes[i].titulo, nome) == 0) 
        {
            exibirFilme(i);

            int qnt;
            printf("Informe a quantidade: ");
            scanf("%d", &qnt);

            if (qnt > 0 && qnt <= filmes[i].quantidade) {
                filmes[i].quantidade -= qnt;
                printf("Estoque atualizado com sucesso!\n");

            } 
            else 
            {
                printf("Quantidade insuficiente em estoque!\n");
            }

        }
    }
}

void devoluçãoFilme (char *nome)
{
    int i;
    Filme f = filmes[i];
    for (int i = 0; i < totalFilmes; i++) 
    {
        if (strcmp(filmes[i].titulo, nome) == 0) 
        {
            exibirFilme(i);

            int qnt;
            int valor=15;
     
            printf ("Informe a quantidade de volumes alugados\n");
            scanf("%d", &qnt);

            if (qnt > 0) {
                filmes[i].quantidade += qnt;
                printf("Estoque atualizado com sucesso!\n\n\n\n");

            } 
            
            printf("====LOCADORA GRIMMITHS====\n");
            printf("R$ 15 por filme locado\nQuantidade           %d\n", qnt); 
            printf("Total:               R$%d\n", valor*qnt);
            printf("==========================\n\n\n");

        }
    }
}

void excluirFilme(char *nome)
{
    int index = -1;

    for (int i = 0; i < totalFilmes; i++)
    {
        if (strcmp(filmes[i].titulo, nome) == 0)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        for (int i = index; i < totalFilmes - 1; i++)
        {
            filmes[i] = filmes[i + 1];
        }
        totalFilmes--;
        printf("Filme excluído com sucesso!\n");
    }
    else
    {
        printf("Filme não encontrado!\n");
    }
}


void salvarFilmes() {
    FILE *file = fopen(ARQUIVO, "w");
    if (file == NULL) {
        printf("Erro ao salvar os filmes!\n");
        return;
    }

    for (int i = 0; i < totalFilmes; i++) {
        fprintf(file, "\"%s\",\"%s\",%d,%.1f,%d\n", 
                filmes[i].titulo, 
                filmes[i].diretor, 
                filmes[i].anoLancamento, 
                filmes[i].classificacao, 
                filmes[i].quantidade);
    }

    fclose(file);
}

void carregarFilmes() {
    FILE *file = fopen(ARQUIVO, "r");
    if (file == NULL) {
        return; // Se o arquivo não existir ou não puder ser aberto, simplesmente retorna
    }

    while (fscanf(file, "\"%[^\"]\",\"%[^\"]\",%d,%f,%d\n", 
                  filmes[totalFilmes].titulo, 
                  filmes[totalFilmes].diretor, 
                  &filmes[totalFilmes].anoLancamento, 
                  &filmes[totalFilmes].classificacao, 
                  &filmes[totalFilmes].quantidade) != EOF) {
        totalFilmes++;
    }

    fclose(file);
}
