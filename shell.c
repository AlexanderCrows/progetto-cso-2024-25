#include shell.hèèèèè
#include fs.h
//Implemento i comandi shell 
//Collegamento main-shell


//Comandi per info
void list(){
  printf("Comandi disponibili:\n");
  printf("format <filename><size> -Inizializza il file system\n ");
  printf("mkdir <dirname>      -Crea una nuova directory\n");
  printf("cd <dirname>        -Cambia la directory corrente\n");
  printf("touch <filename>    -Crea un nuovo file vuoto");
  printf("cat <filename>      -Mostra il contenuto di un file\n");
  printf("ls                  -Elenca i file e le directory correnti\n");
  printf("append<file><test>  -Aggiunge testo alla fine di un file\n");
  printf("rm <file/dir>       -Rimuove un file o una directory\n");
  printf("ma <comando>        -Mostra la guida dettagliata di un comando\n");
  printf("close");
}
/*Descrive il comando*/
/*void man(char* cmd){
  if(strcmp(cmd,"format")==0){
    printf("");
  }else if(strcmp(cmd,"mkdir")==0){
    printf("");
  }else if(strcmp(cd,"cd")==0){
    printf();
  }else if(strcmp(cmd,"touch")==0){
    printf();
  }else if(strcmp(cmd,"cat")==0){
    printf():
  }else if(strcmp("ls"))==0{
    printf();
  }else if(strcmp("append(char* file_name,char* txt): aggiunge testo txt al file name")){
  }else i
  }
  f(strcmp("rm (char* name): rimuove un file/directory con nome name")
  )){
  /*Caso in cui il comando non è presente nella lista1*/
  //printf("Comando non presente nella lista dei comandi shell");
}
*/

//----Comandi di shell
/*Inizializza il file system*/
int format(const char* filename,int size){
  return initialize_FS(filename,size);
}
/*Crea la cartella con nome dirname*/
int mkdir(const char* dirname){
  return createDirectory(dirname);
}
/*Mi sposto in una directory*/
int cd(const char* dirname){
  return changeDirectory(dirname);
}
/*Crea un file vuoto con nome filename*/
int touch(const char* filename){
  return createFile(filename);
}
/*Usato  per stampare il contenuto di un file*/
int cat(const char*filename){
  return readFile(filename);
}
/*Lista la directory corrente*/
int ls(){
  //nel caso in cui non ci siano file dico "Nessun file da
  return printDirectory();
}
/*Aggiunge il testo txt al file nella directory corrente*/
int append (const char* file,const char* txt){
  return writeFile(file,txt);
}
/*Rimuove il file o una sottodirectory*/
int rm(const char* name){
  return remove(name); //dovrò fare un controllo se sarà una directory o un file, ancora da vedere il come//
}
