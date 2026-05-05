#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
    float nota1[100], nota2[100], media[100];
    float *p_nota1, *p_nota2, *p_media;
    int d, q;

    // inicialização dos ponteiros
    p_nota1 = nota1;
    p_nota2 = nota2;

    // entrada de dados
    do
    {
        printf("Digite a quantidade de alunos: ");
        scanf("%i", &q);
    }
    while (q < 0 || q > 100);

    for (d = 0; d < q; d++, p_nota1++, p_nota2++)
    {
        do
        {
            printf("Aluno %d - digite a nota 1: ", d + 1);
            scanf("%f", p_nota1);
        }
        while (*(p_nota1) < 0 || *(p_nota1) > 10);

        do
        {
            printf("Aluno %d - digite a nota 2: ", d + 1);
            scanf("%f", p_nota2);
        }
        while (*(p_nota2) < 0 || *(p_nota2) > 10);
    }

    // resetando ponteiros
    p_nota1 = nota1;
    p_nota2 = nota2;
    p_media = media;

    // cálculo da média
    for (d = 0; d < q; d++)
    {
        *p_media++ = ((*p_nota1++) + (*p_nota2++)) / 2;
    }

    // resetando novamente
    p_nota1 = nota1;
    p_nota2 = nota2;
    p_media = media;

    printf("\nLendo os elementos:\n");
    printf("\tNota1\tNota2\tMedia\n");

    for (d = 0; d < q; d++)
    {
        printf("Aluno %d\t%.2f\t%.2f\t%.2f\n",
               d + 1, *p_nota1++, *p_nota2++, *p_media++);
    }

    // resetando para uso final
    p_media = media;

    // resultado final
    for (d = 0; d < q; d++, p_media++)
    {
        if (*(p_media) >= 7)
        {
            printf("\nAluno %d - Media %.2f = Aprovado", d + 1, *(p_media));
        }
        else if (*(p_media) >= 4)
        {
            printf("\nAluno %d - Media %.2f = Em recuperacao", d + 1, *(p_media));
        }
        else
        {
            printf("\nAluno %d - Media %.2f = Reprovado", d + 1, *(p_media));
        }
    }

    return 0;
}
