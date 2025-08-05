#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

//---In questo file metterò le struct varie con le relative definizioni di funzioni---
#define BLOCK_SIZE 4096
#define MAX_BLOCKS 1024
#define MAX_INODES 128 //Perchè 4096/32
#define MAX_POINTERS 12

---Tipologia Inode---
//Struttura per rappresentare l'intero file system
typedef struct{
  int identifier;   
  int total_inodes; 
  int total_blocks; 
  int free_inodes; 
  int free_blocks; 
  
  //Indici per le bitmap e la tabella degli inode
  int block_bitmap[BLOCK_SIZE]; //lista blocchi liberi
  int inode_bitmap[BLOCK_SIZE];
  int inode_table_start_index;
  int data_blocks_start_index;
}Superblock; 

//---Directory_Entry
typedef struct{
  char name[30];
  int inode; 
}Dir_Entry;

typedef struct{
  int id;  
  int size; //usato per file
  int is_dir; 
  int direct_free; //usato per vedere nel momento in cui andiamo a fare il controllo della directory vuota
  struct Inode padre;
  
  int empty_pointers;
  int direct[MAX_POINTERS]; //Se è un file memorizza direttamente le aree di per leggerlo
                            //mentre se è una directory punta a delle Dir_Entry
}Inode;


extern Superblock s;

//Funzioni ausiliarie base

int searchInodeInFS();
int searchFileInDirectory();

int search_free_inode();
int search_free_data_block();
