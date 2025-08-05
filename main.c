//Qui definisco il programma principale da runnare
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define EXIT_SUCCESS 0
#define EXIT_FALURE 1

#include <process_stuff.h>
#include <signal.h>
//#include <process_stuff.h>  //main.c <-- process_stuff.h

#define MAX_LINE 2048
#define MAX_TOKENS 256
void exec_cmd(char* argv[MAX_TOKENS],int argc){
  int res; //memorizza il valore restituito dal singolo comando
  pid_t pid = fork();
  
  if(pid == -1){
    perror("fork error");
    exit(EXIT_FAILURE);
 
  char* cmd=argv[0]; //comando in ingresso
  
  pid_t pid=fork();
  
  
  //I processi figli eseguono i comandi
  if(pid==0){
    //-----PROCESSO FIGLIO------
    if(strcmp(cmd,"list")==0){
      list();
    }
    //Da vedere
    /*else if(strcmp(cmd,"man")==0){
      char* command=argv[1];
      if(command==NULL){
        printf("Comando non valido!");
        return;
      }
      man(command);
    }*/
    //crea il file system
    else if(strcmp(cmd,"format")==0){
      char* filename=argv[1];
      if(filename==NULL){
        printf("Nome del file non specificato\n");
        _exit(1);
      }
      char* size= argv[2];
      if(size==NULL){
        printf("Taglia non specificata");
      }
      ret=format(filename,size);
      if(ret<0){
        printf();
      }
      
    }else if(strcmp(cmd,"mkdir")==0){
      char* dirname=argv[1];
      if(dirname==NULL){
        printf("Cartella non specificata\n");
      }
      ret=mkdir(dirname);
      if(ret<0){
        
      }
    }else if(strcmp(cmd,"cd")==0){
      char* dirname=argv[1];
      if(dirname==NULL){
        printf("Cartella non specificata\n");
      }
      cd(dirname);
    }else if(strcmp(cmd,"touch")==0){
      char* filename=argv[1];
      if(filename==NULL){
        printf();
      }
      touch(filename);
    }else if(strcmp(cmd,"cat")==0){
      char* filename=argv[1];
      if(filename==NULL){
        printf("Nome del file non specificato\n");
      }
      cat(filename);
    }else if(strcmp(cmd,"ls")==0){
      ls();
    }else if(strcmp(cmd,"append")==0){
     char* filename=argv[1];
     if(filename==NULL){
        printf("Nome del file non specificato!\n");
     }
     char* text=argv[2];
     if(text==NULL){
      printf("Testo da aggiungere non presente!\n");
     }
     append(filename,txt);
     
    }else if(strcmp(cmd,"rm")==0){
      char* name; //può essere file o directory
      if (name==NULL){
        printf("Nome del file/cartella non specificato\n");
      }
      ret=rm(name);
      if(ret<0){
        printf("Errore: questo file non può essere rimosso.\n");
      }
    }else{
      printf("Errore: comando sconosciuto.\n");
      printf("Usa 'list' per la lista dei comandi");
    }

}
  }else{
    //--PROCESSO PADRE----
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
      argv[argc++] = dup_string(token); 
      token = strtok(NULL,"\t\n");
    }
    argv[*argc] = NULL;
}


int do_shell(const char* prompt){
  print("Comandi utili:\n");
  printf("list: lista i comandi disponibili\n");
  //Da decidere:printf("man comando:se si desidera una descrizione più approfondita di un comando /n");
  for(;;){
    printf("%s"r,prompt);
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
