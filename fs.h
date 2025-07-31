//In questo file dichiaro tutte le funzioni di sistema

int initialize_FS(char* filename,int size);
int createDirectory(char* dirname);
int changeDirectory(char* dirname);
int createFile(char* filename);
int readFile(char* filename);
void printDirectory();
int writeFile(char* filename,char* txt);
int remove(char* name);//Può essere un file o directory

