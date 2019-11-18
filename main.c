#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    printf("Enter start address :\n");
    int st;
    scanf("%d",&st);
    printf("\n\n");
    FILE *ip;
    FILE * op;
    int j=0,i=0,lenA,lenB,lenC,k,sum=0,ar[4],u,p;
    char loc;
    char ad[5];
    char buf[50];
    char dum[6][6];
    ip=fopen("Input.txt","r");
    op=fopen("estab.txt","w");
    while(fgets(buf,50,ip)!=NULL)
    {
        char * token = strtok(buf," ");
        if(strcmp("H",token)==0)
            {
                    i++;
                    token = strtok(NULL," ");
                    if(token==NULL)
                    {printf("\n");
                    fprintf(op,"\n");
                        break;}
                    printf("%s ",token);
                    fprintf(op,"%s ",token);
                    token = strtok(NULL," ");

                    if(i==1)
                       {
                           printf("%d ",(atoi(token)+st));
                           fprintf(op,"%d ",(atoi(token)+st));
                            token = strtok(NULL," ");
                           lenA=atoi(token);
                           printf("%d",lenA);
                           fprintf(op,"%d ",lenA);
                       }
                    else if(i==2)
                    {   printf("%d ",(atoi(token)+st+lenA));
                        fprintf(op,"%d ",(atoi(token)+st+lenA));
                        token = strtok(NULL," ");
                        lenB=atoi(token)+lenA;
                        printf("%d",atoi(token));
                        fprintf(op,"%d",atoi(token));
                        }

                    else if(i==3)
                    {
                        printf("%d ",(st+lenB));
                        fprintf(op,"%d ",(st+lenB));
                        token = strtok(NULL, " ");
                        lenC=atoi(token)+lenA+lenB;
                        printf("%d",atoi(token));
                        fprintf(op,"%d",atoi(token));
                    }
                    printf("\n---------------\n");
                    fprintf(op,"\n\n");


            }
        else if(strcmp("D",token)==0)
        {
            while (token != NULL)
            {

                    if(i==1)
                    {         p=0;
                            token = strtok(NULL, " ");

                            sum=0;
                            for(k=0;k<6;k++)
                                sum=sum+token[k];
                               // printf("%d",sum);
                            for(u=0;u<3;u++)
                                {if(sum==ar[u])
                                    {printf("\n*duplicate found*\n");
                                    break;}
                                }
                                if(u==3){
                                            ar[p]=sum;
                                            p++;
                                            printf("%s ",token);
                                            fprintf(op,"%s ",token);
                                }
                                else{
                                    j=2;
                                }

                           // printf("%d .",sum);

                            token = strtok(NULL, " ");
                            if(j<2)
                            {
                            printf("%d\n",(atoi(token)+st));
                            fprintf(op,"%d\n",(atoi(token)+st));
                            }

                    }
                    else if(i==2)
                        {
                            token = strtok(NULL, " ");
                            printf("%s ",token);
                            fprintf(op,"%s ",token);
                            token = strtok(NULL, " ");
                            if(j<6)
                            {
                                printf("%d\n",(atoi(token)+lenA+st));
                                fprintf(op,"%d\n",(atoi(token)+lenA+st));
                            }

                    }
                  else if(i==3)
                        {
                            token = strtok(NULL," ");
                            printf("%s ",token);
                             fprintf(op,"%s ",token);
                            token = strtok(NULL," ");
                            if(j<9)
                            {
                                printf("%d\n",(atoi(token)+lenB+st));
                                fprintf(op,"%d\n",(atoi(token)+lenB+st));
                            }

                    }
                    j++;
            }

        }



    }

    fclose(op);
    fclose(ip);
    return 0;
}
