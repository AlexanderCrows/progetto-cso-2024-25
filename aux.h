//---In questo file metterò le struct varie con le relative definizioni di funzioni---
#define MAX_INODES 128  //Perchè 4096/32
#define MAX_BLOCKS 1024
#define BLOCK_SIZE 4096
---Tipologia Inode---
//Struttura per rappresentare l'intero file system
typedef struct{
  int identifier;   //identificatore del superblocco
  int total_inodes; //number of inodes
  int total_blocks; //numero totale di blocchi
  
  int inode_size; //quanti byte possono avere gli inode
  int free_inodes; // numero di inode liberi
  int free_blocks; //
  int bitmap[BLOCK_SIZE]; //lista blocchi liberi
  int inode_table[MAX_INODES]; //
}Superblock; 

typedef struct{
  char name[20];
  int inode; 
}Dir_Entry;


typedef struct{
  int id;  
  int size; 
  int type; 
  int direct[12];
  
}Inode;


extern Superblock s;

//Funzioni ausiliarie base
