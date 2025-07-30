//Qui definisco il programma principale da runnare
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 2048
#define MAX_TOKENS 256



void exec_cmd(char* argv[MAX_TOKENS],int argc){
  char* cmd=argv[0];
  pid_t pid=fork();
  if(pid==-1){
    perror("fork error");
    exit(EXIT_FAILURE);
  }
  if(pid==0){
  
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
    
    else if(strcmp(cmd,"format")==0){
      char* filename=argv[1];
      if(filename==NULL){
        printf("Nome del file non specificato\n");
      }
      char* size= argv[2];
      if(size==NULL){
        printf("Taglia non specificata");
      }
      format(filename,size);
    }else if(strcmp(cmd,"mkdir")==0){
      char* dirname=argv[1];
      if(dirname==NULL){
        printf("Cartella non specificata\n");
      }
      mkdir(dirname);
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
      rm(name);
    }else{
      //Caso in cui nessun comando corrisponde a quelli della shell//
      printf("Errore: comando sconosciuto. Usa 'list'.\n");
    }
  /**/
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
void initiliazeFS(){
  char response[10];
  printf("È la prima volta che usi questo FS?[Y/N]%s",response);
  if(strcmp(response,"Yes"){
    printf("Inizializzazione.../n");
    fs_init(); //sarà una funzione che inizializzerà il sistema
    return;
  }else{
    printf("Stai usando il FS corrente");
    ls();
  }
}

int do_shell(const char* prompt){
  initiliazeFS();
  print("Comandi utili:/n");
  printf("list: lista i comandi disponibili/n");
  printf("man comando:se si desidera una descrizione più approfondita di un comando /n");
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
