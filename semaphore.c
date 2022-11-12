#include <stdio.h>
int m=1,f=0,e=5;
int wait(int s){
  while(s<=0);
  s=s-1;
  return s;
}
int signal(int s){
  s=s+1;
  return s;
}
void producer(){
  m=wait(m);
  e=wait(e);
  f=signal(f);
  printf("Producer produces item\n");
  m=signal(m);
}
void consumer(){
  m=wait(m);
  f=wait(f);
  e=signal(e);
  printf("Consumer condumes item\n");
  m=signal(m);
}
int main(){
  int o;
  do{
    printf("Choose operation\n1.Produce item\n2.Consume item\n3.Exit\n");
    scanf("%d",&o);
    switch(o){
      case 1:if(m==1 && e!=0)
          producer();
        else
          printf("Producer is waiting.......\n");
        break;
      case 2:if(m==1 && f!=0)
          consumer();
        else
          printf("Consumer is waiting.......\n");
    }
  }while(o!=3)
}