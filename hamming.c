#include <stdio.h>

int main()
{
    int input[4],par[4],npar[4],cod[8],dec[8],c,c1,c2,c3,c4,i;
    printf("\n Entre com o valor de entrada \n");
    for(i=0;i<4;i++)
    {
        scanf("%d",&input[i]);
    }
    par[0]=input[0]^input[2]^input[3];
    par[1]=input[0]^input[1]^input[3];
    par[2]=input[1]^input[2]^input[3];
    par[3]=input[0]^input[1]^input[2]^input[3]^par[0]^par[1]^par[2];
    for(i=0;i<8;i++)
    {
        if(i<4)
        {
            cod[i]=input[i];
        }
        else
        {
            cod[i]=par[i-4];
        }
    }
    printf("\nMensagem Codificada: ");
    for(i=0;i<8;i++)
    {
        printf("%d",cod[i]);
    }

    printf("\n Entre com o valor de recebimento \n");
    for(i=0;i<8;i++)
    {
        scanf("%d",&dec[i]);
    }
    npar[0]=dec[0]^dec[2]^dec[3];
    npar[1]=dec[0]^dec[1]^dec[3];
    npar[2]=dec[1]^dec[2]^dec[3];
    npar[3]=dec[0]^dec[1]^dec[2]^dec[3]^dec[4]^dec[5]^dec[6]^dec[7];
    c1= par[0]^npar[0];
    c2= par[1]^npar[1];
    c3= par[2]^npar[2];
    c4= par[3]^npar[3];
    printf("%d%d%d%d",c1,c2,c3,c4);
    if (c4 == 0)
    {
        if (c1==0 && c2==0 && c3==0)
        {
            printf("\n Mensagem recebida sem erros\n");
        }
        else
        {
            printf("\n Erro Duplo \n");
        }
    }
    else
    {
        if (c1==1 && c2==1 && c3==0)
        {
            printf("\n Erro simples no bit 1 \n");
        }
        else if (c1==0 && c2==1 && c3==1)
        {
            printf("\n Erro simples no bit 2 \n");
        }
        else if (c1==1 && c2==0 && c3==1)
        {
            printf("\n Erro simples no bit 3 \n");
        }
        else if (c1==1 && c2==1 && c3==1)
        {
            printf("\n Erro simples no bit 4 \n");
        }
        else if (c1==0 && c2==0 && c3==0)
        {
            printf("\n Erro na paridade \n");
        }
    }
}