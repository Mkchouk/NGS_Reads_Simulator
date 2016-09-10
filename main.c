#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>

char insrer()
{
    char c; int nbrale=0;
    nbrale=rand()%4;
   // printf("nbrale= %d\n",nbrale);
    switch (nbrale){
case 0:
    c='A';
    break;
case 1:
    c='C';
    break;
case 2:
    c='G';
    break;
case 3:
    c='T';
    break;
}
return c;
}
char substitution(char c)
{   int nbrale=0;
    nbrale=rand()%3;
    if(c=='A')
    {
        switch (nbrale)
        {
        case 0:
            c='T';
            break;
        case 1:
            c='C';
            break;
        case 2:
            c='G';
            break;
        }
    }
    if(c=='C')
    {
        switch (nbrale)
        {
        case 0:
            c='T';
            break;
        case 1:
            c='A';
            break;
        case 2:
            c='G';
            break;
        }
    }
    if(c=='T')
    {
        switch (nbrale)
        {
        case 0:
            c='A';
            break;
        case 1:
            c='C';
            break;
        case 2:
            c='G';
            break;
        }
    }
    if(c=='G')
    {
        switch (nbrale)
        {
        case 0:
            c='T';
            break;
        case 1:
            c='C';
            break;
        case 2:
            c='A';
            break;
        }
    }
    return c;
}
int main()
{
 FILE* fichier=NULL;fichier= fopen("Reads_exact.fa","r");

 FILE* fichier1 = NULL; fichier1 = fopen("fichier_reads_simulated.fa", "w+");
    unsigned int TAILLE_MAX=100001;

    char *sequence1 = NULL; sequence1 = malloc(sizeof(char) * 100000);
    int i=0; int inser=0; int del=0;int sub=0;int j=0;
       while(fgets(sequence1,TAILLE_MAX, fichier)!= NULL)
       {
            if(sequence1[0]=='>')
            {
                fputs(sequence1,fichier1);printf("\n%s",sequence1);
            }
            char *sequence = NULL;sequence = malloc(sizeof(char) * 100000);
            fgets(sequence,TAILLE_MAX, fichier);
            if(sequence[0]!='>')
            {
          float randomValue=0.0;char C;int cpt=0;
               srand(time(NULL));
            j=0;inser=0;del=0;sub=0;
            for(i=0;i<strlen(sequence)-2;i++)
               {   randomValue=(rand()*1.0) / RAND_MAX;
                  //  printf("randomValue: %f \n\n",randomValue);
                    //printf("cpt: %d ",cpt++);
                    if((randomValue>=0.0) && (randomValue<=0.075))
                    {
                       fputc(sequence[i],fichier1);
                        C=insrer();
                        fputc(C,fichier1);
                        inser++;j=j+1;
                    }
                   if((randomValue>0.075) && (randomValue<0.12))
                    {
                        del++;j=j+1;
                    }
                   if((randomValue>=0.12) && (randomValue<0.15))
                    {   sequence[i]=substitution(sequence[i]);
                        fputc(sequence[i],fichier1);
                        sub++;j=j+1;
                    }
                   if((randomValue>=0.15) && (randomValue<=1.0))
                    {fputc(sequence[i],fichier1);
                        j=j+1;
                    }

               }
               printf("J= %d",j);
               // printf(" le dernier caractère: %c",sequence[strlen(sequence)-1]);
                    fprintf(fichier1,"%c",sequence[strlen(sequence)-1]);
                                }
            printf("\nLongueur de la sequence originale : %d",strlen(sequence));
            printf("\nnombre d'insertion: %d ",inser);
            printf("\nnombre de deletion: %d ",del);
            printf("\nnombre d'ajout: %d ",inser-del);
            printf("\nnombre de substitutions: %d ",sub);
            printf("\nsize of simulated Read: %d ",strlen(sequence)+inser-del-1);
            printf("\n------------------------------------------------------------------------");
       } //End While
        rewind(fichier1);
        while(fgets(sequence1,TAILLE_MAX, fichier1)!= NULL)
       {
            if(sequence1[0]=='>')
            {
                printf("\n%s",sequence1);
            }
            char *sequence2 = NULL;sequence2 = malloc(sizeof(char) * 100000);
            fgets(sequence2,TAILLE_MAX, fichier1);
            printf("longueur du read simulated: %d",strlen(sequence2));

       }
   // printf("Hello world!\n");
    return 0;
}
