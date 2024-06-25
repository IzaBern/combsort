#include <stdio.h>
#include <string.h>
#define TAM 1000

void leia_notas(int cod[TAM], char nome[TAM][100], float nota1[TAM], float nota2[TAM])
{
    for (size_t i = 0; i < TAM; i++)
    {
        scanf("%d,%[^,],%f,%f",&cod[i],nome[i],&nota1[i],&nota2[i]);
    }
}
void media_notas(float n1[TAM], float n2[TAM], float media[TAM])
{
    for (size_t i = 0; i < TAM; i++)
    {
        media[i] = (n1[i] + n2[i]) / 2.0;
    }
}
void combsort(int cod[TAM], char nome[TAM][100], float media[TAM])
{
    int i, j, c, h = TAM;
    while(h>1 || c == 1)
    {
        h = h/1.3;
        if(h<1) h=1;
        c=0;
        for (i = 0, j=h; j < TAM; i++, j++)
        {
            if(media[i]>media[j])
            {
                float aux_float = media[i];
                media[i] = media[j];
                media[j] = aux_float;

                int aux_int = cod[i];
                cod[i] = cod[j];
                cod[j] = aux_int;

                char aux_str[100];
                strcpy(aux_str,nome[i]);
                strcpy(nome[i],nome[j]);
                strcpy(nome[j],aux_str);

                c = 1;
            }
        }
    }
}
void escreva_notas(int cod[TAM], char nome[TAM][100], float media[TAM])
{
    for (size_t i = 0; i < TAM; i++)
    {
        if (media[i]>=6)
        {
            printf("%d,%s,%.2f\n",cod[i],nome[i],media[i]);
        }
    }
}
int main()
{
    int cod[TAM];
    char nome[TAM][100];
    float nota1[TAM], nota2[TAM], media[TAM];

    leia_notas(cod,nome,nota1,nota2);
    media_notas(nota1, nota2, media);
    combsort(cod,nome,media);
    escreva_notas(cod,nome,media);
    return 0;
}