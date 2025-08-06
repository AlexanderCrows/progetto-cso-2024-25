#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

//---In questo file metterò le struct varie con le relative definizioni di funzioni---

/*Costanti di sistema*/
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
  int inode_bitmap_start_index;
  int data_block_bitmap_start_index;
  int inode_table_start_index;
  int data_blocks_start_index;
}Superblock; 

/*---Directory_Entry----*/
typedef struct{
  char name[30];
  int inode; 
}Dir_Entry;

/*----Struttura Inode----*/
typedef struct{
  int id;  
  //---Per file
  int size; 
  //---Per directory
  struct Inode padre; //usato nel caso in cui vogliamo tornare nella directory padre
  int direct_free; //usato per vedere nel momento in cui andiamo a fare il controllo della directory vuota
  
  //---Usato per entrambi
  int is_dir;
  int empty_pointers;
  int direct[MAX_POINTERS]; 
}Inode;

/*direct[MAX_POINTERS] 
Se l'inode è un file memorizza direttamente le aree di memoria per leggerlo.
Se l'inode è una directory i puntatori puntano a Dir_Entry
*/

//Dichiarazioni di variabili globali
extern Superblock superblock;


//Funzioni a basso livello
int searchInodeInFS();
int searchFileInDirectory();

int search_free_inode();
int search_free_data_block();

#endif FILESYSTEM_H
