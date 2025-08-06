#include aux.h

extern Superblock s;
extern Inode* current_dir;



int searchInodeInFS(){
    
  
}
int searchFileInDirectory(char* filename){
}

//Funzione per trovare un inode libero
int search_free_inode(){
  for(int i=0;i<MAX_INODES;i++){
    if(s.inode_bitmap[i]==0){
      s.inode_bitmap[i]=1;
      return i;
    }
  }
  return -1;
}

//Funzione per trovare un data_block libero
int search_free_data_block(){
  for(int i=0;i<MAX_BLOCKS;i++){
    if(s.block_bitmap[i]==0){
      s.block_bitmap[i]=1;
      return i;
    }
  }
  return -1;
}

