#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"

int main(int argc, char **argv){
  printf("Checking the parentheses in argv arguments\n");
  int i,N,j;
  char c;
  
  Stack s;
  s.size = 0;

  for(i=1;i<argc;i++){
     N = 0;
     for(j=0;j<strlen(argv[i]);j++){
       /* Use stack to help with the parentheses*/
      if(argv[i][j]=='{'||argv[i][j]=='[')
        {
          push(&s,argv[i][j]);
        }
      else if((argv[i][j]=='}'))
      {
          if(s.size == 0)
          {
            printf(" %s Not match \n",argv[i]);
            N = 1;
            break;
          }
          else
          {
               c = pop(&s);
              printf("find %c ,pop %c\n",argv[i][j],c);
              if(c!='{')
              {
                pop_all(&s);
                printf(" %s Not match \n",argv[i]);
               N = 1;
               break;
               }
          }
       
      }
      else if((argv[i][j]==']'))
      {
          if(s.size==0)
          {
            printf(" %s Not match \n",argv[i]);
            N = 1;
            break;
          }
          else{
            c = pop(&s);
            printf(" find %c , pop %c\n",argv[i][j],c);
            if(c!='[')
            {
              pop_all(&s);   
              printf(" %s Not match \n",argv[i]);
              N = 1;
              break;
            }
          }
          
      }
     }
      if(N==0&&s.size==0)
     printf("%s is match \n",argv[i]);
     else if(N==0&&s.size!=0)
      {
         printf("%s is not match \n",argv[i]);
         pop_all(&s);
      }
     
  }
   return 0;
}
