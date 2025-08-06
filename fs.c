/*
Commento di cosa fa questo file:
implemento i comandi di sistema:
*/
#include aux.h
#include fs.h

//Variabili globali
extern Superblock s;
extern Inode* current_dir_inode;




/*
int seekFile(int fd, off_t offset){
  

}
*/

/*Data inizio funzione initialize_FS 06/08/2015:
Capire per prima cosa come inizializzare 
il file system e aggiungere un file
per fare una run*/

//Funzione per inizializzare il fileSystem
int initialize_FS(char* filename,int size){
  //Apri il filesystem, se non esiste lo crea
  int fd=open(filename,O_RDWR|O_CREATE,0660);
  if(fd<0){
    printf("Errore nell'apertura del file\n");
    return -1;
  }
  //Impostare la taglia per il filesystem
  int ftruc_ret=ftruncate(fd,size);
  if(ftrunc_ret==-1){
    printf("Errore in ftruncate\n");
    return -1;
  }
  //qui avviene la mappatura in memoria
  void* mem=mmap(nullptr,size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
  if(mem == -1){
    printf("La mappatura non è andata a buon fine");
    close(fd);
    return -1;
  }

  //---Inizializzazione Superblocco---                                      
  s.total_inodes = MAX_INODES;
  s-total_blocks = MAX_BLOCKS;
  s.free_inodes = MAX_INODES;
  s.free_blocks = MAX_BLOCKS;
  
  //---Inizializzo gli indici delle bitmap---
  //dopo l'allocazione del Superblocco iniziano le bitmap
  s.inode_bitmap_start_idx=sizeof(Superblock);                                 
  s.data_block_bitmap_start_idx = s.inode_bitmap_start_idx + INODE_BITMAP_SIZE ;
  s.inode_table_start_idx = s.data_block_bitmap_start_idx +  DATA_BLOCK_BITMAP_SIZE;
  s.data_blocks_start_idx = s.inode_table_start_idx + ;
  
  //Inizializzo le aree di memoria per bitmap e tabelle
  memset(mem+s.inode_bitmap_start_idx,0,INODE_BITMAP_SIZE);
  memset(mem+s.data_block_bitmap_start_idx,0,DATA_BLOCK_BITMAP_SIZE);
  memset(mem+s.inode_table_start_idx,0,INODE_TABLE_SIZE);
  
  /*Ricordarsi di aggiungere le costanti nell'aux.h*/
  //Salvataggio avvenuto con successo
  printf("Salvataggio avvenuto con successo");
  return 0;
}
/*
//Creazione della directory
int createDirectory(char* dirname){
    int i=searchFreeInode();
    if(i==-1){
      printf("Nessun Inode disponibile per la directory");
      return -1;
    }
    
    
   //qui avviene la mappatura in memoria
   
}

*/
//Cambio della directory
/*int changeDirectory(char* dirname){
  if(strcmp(dirname,".")){
    printf("Nessun cambio di cartella");
  }else if(strcmp(dirname,"..")){
    Inode padre=ref->padre;
    ref=padre;
    return 0;
  }else{
    Inode dir=searchSubFolder();
    ref=dir;
  }
}
*/

int createFile(char* filename){
  int fd=
  //qui avviene la mappatura in memoria
}

/*
int readFile(char* filename){
    
  Dir_Entry* d=searchFileInCurrentDir();
   //ref->Inode_Directory_Corrent->[Directory_table]->
   //Quindi vado a leggere il numero dell'inode nella Directory_Table e lo cerco
   //nel sistema con una funzione
    for(int i=0;i<12;i++){
      Dir_entry dir=ref->direct[i];
      if(strcmp(dir.name,filename)==0){
        Inode file=searchInodeFile(filename);
        //Leggo blocco per blocco
        for(int j=0<;j<MAX_BLOCKS;j++){
          if(file.direct[j].isused){
            //Se il blocco è occupato lo vado a leggere
          }
        }
        printf("Lettura avvenuta con successo");
        return 0;
      //Come leggere un file
      //Forse implementare un un used_blocks che mi tiene traccia
      //Di quanti li sto usando oppure
      
     
    }
  }
 //Non ho trovato il file all'interno della directory corrrente
 printf("File non trovato");
 return -1;
 }
 */
 
 
//Funzione per listare il contenuto di una directory
void printDirectory(){
  if(empty_pointers==0){
    printf("La directory corrente è vuota!");
  }
  //Altrimenti vado direttamente a leggere
  for(int i=i;i<MAX_POINTERS;i++){
    int ptr_direct= ref->direct[i]; 
    //adesso sto pensando ma ref->direct[i] io vado ad accedere
    al valore del puntatore e quindi per prendere la dir_entry
    //dovrò fare un altro accesso
    if(ptr_direct!=NULL){
      Dir_Entry* entries = (Dir_entry*) data_blocks[block_id];
      if(strcmp(d.name,name)==0){
        Inode toprint=searchInodeInFS(); //qui devo andare a cercare nella lista degli inode del superblocco.
        printf("Tipo:%s  Nome:%s\n");
      }
    }
  }
  
}

/*
//Funzione per scrivere su un file
int writeFile(char* filename,char* txt){
  int fileInode= searchInodeInFS(ref,filename);
  if (fileInode==-1){
    printf("Error: no file with name %s in current dir\n.",filename);
    return -1;
  }
  //Altrimenti scrivo sul file
  int fd=open(fd,,)
  seekFile(fd,);
  
  
}
*/

/*
//Funzione per rimuovere un file o una sottodirectory
int remove(char* name){
  if(current_dir.free_spa
  for(int i=0;i<12;i++){
    Dir_Entry d =ref->direct[i];
    if(d!=NULL){
      if(strcmp(d.name,name)==0){
        char response[20];
        Inode toremove=searchInodeInFS();
          //Caso rimuovo una cartella
          if(toremove.isdir){
            
            if(toremove.n_entries){
                //Se è vuota             
            }else{
              //Se non è vuota  
              printf("Errore:La cartella che stai cancellando contiene file");
              
            }
          }
          }else{
          //Caso in cui rimuovo un file
            
        }
      }
    }
  }
 printf("Errore:Non è stato trovato nessun file/directory con il nome %s.",name);
 return -1;
}
*/


