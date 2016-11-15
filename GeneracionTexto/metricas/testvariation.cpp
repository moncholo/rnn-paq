#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h> 
using namespace std;

	
void procesarEntrada(char* filename, char* salida,int delta){
	
	char unChar;
	FILE * outFile = fopen (salida,"w");
	FILE * pFile= fopen (filename,"r");
	char iSecret;
	
	if (pFile!=NULL && outFile!=NULL) {
		
		cout << filename << endl;
		cout << salida << endl;
		
		while (unChar != EOF ) {
			unChar = fgetc (pFile);
			iSecret = rand() % delta;
			if(unChar != EOF){
				if(iSecret != 5)
					fputc(unChar, outFile);
				else
					fputc(rand() % 256, outFile);
			}
		}
		fclose(pFile);
		fclose(outFile);
	}
		
}

int main(int argc, char **argv){
	procesarEntrada(argv[2], argv[3],atoi(argv[1]));
	srand (time(NULL));
	return 0;
}
