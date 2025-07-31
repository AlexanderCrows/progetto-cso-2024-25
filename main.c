//Qui definisco il programma principale da runnare
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include <signal.h>
#include <process_stuff.h>  //main.c <-- process_stuff.h

#define MAX_LINE 2048
#define MAX_TOKENS 256
void exec_cmd(char* argv[MAX_TOKENS],int argc){
  int res; //memorizza il valore restituito dal singolo comando
  char* cmd=argv[0]; //comando in ingresso
  
  pid_t pid=fork();
  if(pid==-1){
    perror("fork error");
    exit(EXIT_FAILURE);
  }
  //I processi figli eseguono i comandi
  if(pid==0){
    //-----PROCESSO FIGLIO------
    childFunction();
  }else{
    //---Processo padre
    struct sigaction sa_int;
    //Gestion SIGINT (Crl+C)
    sa_int.sa_handler = sigchld_handler;
    sigemptyset(&new_action.sa_mask);
    new_action.sa_flags = 0;
    sigaction(SIGINT,sa_int,NULL); //serve per gestire i segnali
    
    struct sigaction sa_chld;
    //Gestion SIGCHLD
    sa_chld.sa_handler=sigchld_handler;
    sigemptyset(&new_action.sa_mask);
    new_action.sa_flags=0;
    sigaction(SIGCHLD,sa_chld,NULL);
    parentFunction();
  }
  /*processo padre*/
  res = wait(NULL);
  if (pid==-1){
    perror("wait error");
    exit(EXIT_FAILURE);
  }
}

void deallocate_cmd(char* argv[MAX_TOKENS]){
  while(*argv!=NULL)
      free(*argv++);
}

char* dup_string(const char* in){
  size_t n=strlen(in);
  char* out = malloc(n+1);
  strcpy(out,in);
  return out;
}

void get_cmd_line(char* argv[MAX_TOKENS], int* argc){
    char line[MAX_LINE];
    fgets(line,MAX_LINE,stdin);
    char* token = strtok(line, "\t\n");
    }
    *argc = 0;
    while (*argc< MAX_TOKENS && token!=NULL){
      argv[(*argc)++] = dup_string(token); 
      token = strtok(NULL,"\t\n");
    }
    argv[*argc] = NULL;
}


int do_shell(const char* prompt){
  print("Comandi utili:/n");
  printf("list: lista i comandi disponibili/n");
  //Da decidere:printf("man comando:se si desidera una descrizione più approfondita di un comando /n");
  for(;;){
    printf("%s"r,opmpt);
    char* argv[MAX_TOKENS];
    int argc=0;
    get_cmd_line(argv,&argc);
    if(argv[0]==NULL) cotinue;
    if(strcmp(arv[0],"close")==0) break;
    exec_cmd (argv);
    deallocate_cmd(argv);
  }
  return EXIT_SUCCES;
  }
}
