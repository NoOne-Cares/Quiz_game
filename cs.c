#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

int main()
{
  FILE *file ,*wellocme,*scores;
  char playername[20];
  char ch,a;
  int p=0,score=0,highScore[4]={0,0,0,0},q=0,total;
  char buffer[2048],canswer[10],answer[10];

    struct detials{           //structure contaning palyer details
    char name[20];
    int round1;
    int round2;
    int round3;
    int highscore;
  }player;

  wellocme=fopen("wellcome.txt","r");  //file contin wellcome text
  while((ch=getc(wellocme))!=EOF)
  printf("%c",ch);
  fclose(wellocme);
  a=tolower(getch());
  system("cls");
  if(a=='s')
  {
      printf("\n\n\n\n\n\n\n\t\t\tRegister Your Name :");   //username input
      scanf("%s",&player.name);
      getch();
      system("cls");
  question:{

      file = fopen("questions.txt", "r");         //file containing questions
      for(int i=0;i<=10;i++)
      {
        canswer[i]=getc(file);                  //array contaning correct answers
      }

      for(int j=0;j<10;j++)                     // nasted loops to print question one by one
      {
        for(int i=0;i<=5;i++)
          {
          fgets(buffer, 2048, file);
          printf("%s", buffer);
          }
          answer[p]=tolower(getch());               //taking answer from the user
          if(answer[p]==canswer[p])                 //comparing them with correct answers
            {
              printf("Correct answer\n\n");
              score++;
            }
            else{
              printf("Wrong Answer\n\n");
              }
            p++;
            highScore[q]=score;
        }
        q++;
        system("cls");
        printf("\n\n\n\n\n\t\t\t\tThnaks you for palying the quiz");
        if(score==10){printf("\n\n\t\t\t\tCounguratlation you have scored perfect score");}
        printf("\n\n\t\t\t\tYou Score is %d out of 10",score);
        printf("\n\n\t\t\t\tpress q to quit");
        if(q<=2){printf("\n\n\t\t\t\tpress p to paly again");
                a=tolower(getch());
                system("cls");
                if(a=='p'){goto question;}
                }
        else{printf("you have exausted all your attepts");}
        getch();        
    }
  }
  if(a=='q')
  {
      printf("Thank You for playing the Quiz ");
  }
  fclose(file);

  player.round1=highScore[0];
  player.round2=highScore[1];
  player.round3=highScore[2];
  player.highscore=highScore[0] >highScore[1] ? (highScore[0] > highScore[2] ? highScore[0] : highScore[2]) : (highScore[1] > highScore[2] ? highScore[1] : highScore[2]) ;
  scores=fopen("records.txt","a+");
  fprintf(scores,"\n%s\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d",player.name,
          player.round1,player.round2,player.round3,player.highscore);
  fclose(scores);
  

  return 0;
}