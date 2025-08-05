#include stdlib.h
#include shell.h

//Definizioni di gestori di segnali
void sigint_handler(int signal){
  printf("SIGNAL %s got signal %d, user pressed Ctrl+C\n",signal);
}
void sigchld_handler(int signal){
  printf("SIGNAL %s got signal %d, child is dead\n",prefix,signal);
}

void childFunction(){
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
        exit(EXIT_FAILURE);
      }
      ret=mkdir(dirname);
      exit(EXIT_SUCCESS);
      if(ret<0){
        
      }
    }else if(strcmp(cmd,"cd")==0){
      char* dirname=argv[1];
      if(dirname==NULL){
        printf("Cartella non specificata\n");
        exit(EXIT_FAILURE);
      }
      cd(dirname);
    }else if(strcmp(cmd,"touch")==0){
      char* filename=argv[1];
      if(filename==NULL){
        printf();
        exit(EXIT_FAILURE);
      }
      touch(filename);
    }else if(strcmp(cmd,"cat")==0){
      char* filename=argv[1];
      if(filename==NULL){
        printf("Nome del file non specificato\n");
        exit(EXIT_FAILURE);
      }
      cat(filename);
      exit(EXIT_SUCCESS);
    }else if(strcmp(cmd,"ls")==0){
      ls();
    }else if(strcmp(cmd,"append")==0){
     char* filename=argv[1];
     if(filename==NULL){
        printf("Nome del file non specificato!\n");
        exit(EXIT_FAILURE);
     }
     char* text=argv[2];
     if(text==NULL){
      printf("Testo da aggiungere non presente!\n");
     }
     append(filename,txt);
     exit(EXIT_SUCCESS);
    }else if(strcmp(cmd,"rm")==0){
      char* name; //può essere file o directory
      if (name==NULL){
        printf("Nome del file/cartella non specificato\n");
        return;
      }
      ret=rm(name);
      exit(EXIT_SUCCESS);
      if(ret<0){
        printf("Errore: questo file non può essere rimosso.\n");
      }
    }else{
      //Caso in cui nessun comando corrisponde a quelli della shell//
      printf("Errore: comando sconosciuto. Usa 'list'.\n");

    }
}

//Il processo padre attente la terminazione del processo figlio
void parentFunction(){
  int status;
  pid_t child_pid = wait(&status);
  if(WIFEXITED(status)){
    printf("Il figlio è terminato con successo");
  }else if (WIFSIGNALED(status)){
    //Il figlio è stato terminato da un segnale (es Ctrl+C).
    if(WTERMSIG(status) == SIGINT){
      printf("\nProcesso figlio terminato da Ctrl+C\n");
    }
  }
  printf("Il figlio %d è morto",child_pid);
}

