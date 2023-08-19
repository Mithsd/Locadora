#include <stdio.h>
#include <string.h>

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

void mostrarFilmes();
Filme cadastrarFilme();
void exibirFilme(int i);
int buscarFilme(char *nome);

Filme filmes[MAX_FILMES];
int totalFilmes = 0;

int main()
{

    int opcao, index;
    char nomeFilme[MAX_STRING];

    do
    {
        printf("\nLocadora de Filmes\n");
        printf("1. Cadastrar Filme\n");
        printf("2. Ver Filmes Cadastrados\n");
        printf("3. Buscar Filme Por Nome\n");
        printf("4. Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:

            if (totalFilmes < MAX_FILMES)
            {
                filmes[totalFilmes] = cadastrarFilme();
                totalFilmes++;
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
            printf("Informe o nome do filme: ");
                getchar(); 
                fgets(nomeFilme, MAX_STRING, stdin);
                nomeFilme[strcspn(nomeFilme, "\n")] = '\0';

                index = buscarFilme(nomeFilme);
                if (index != -1) {
                    exibirFilme(index);
                } 
                else 
                {
                    printf("Filme não encontrado!\n");
                }
                break;

        default:
            printf("\nOpção inválida!\n");
        }

    } while (opcao != 4);

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

int buscarFilme(char *nome)
{
    for (int i = 0; i < totalFilmes; i++) 
        {
            if (strcmp(filmes[i].titulo, nome) == 0) 
            {
                return i;
            }
        }
        return -1; 
}