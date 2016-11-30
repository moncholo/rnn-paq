#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
using namespace std;

vector<string> trigramas;
unsigned long int contadorFinal = 0;

string procesarFrase(string frase, unsigned int largo, unordered_map<string,int>* frecuencias){
	
	string sobrante;
	unsigned int contador = 0;
	if(frase.length() >= largo){
		while((contador) <= (frase.length() - largo)){
			string trigrama;
			
			for(unsigned int i =0; i < largo; i++)
				trigrama+= (frase[contador+i]);
			
			if ((*frecuencias).count(trigrama) == 0){
				(*frecuencias).insert((*frecuencias).begin(), pair<string,unsigned int>(trigrama, 1));
				trigramas.push_back(trigrama);
			}
			else
				(*frecuencias)[trigrama] += 1;
				
			contador++;
		}
	}
	for(unsigned int i = contador; i<frase.length(); i++)
		sobrante = sobrante +frase[i];
	
	return sobrante;
	
}
 
void procesarEntrada(char* filename, int largo, string nombre_salida, unordered_map<string,int>* frecuencias){
	
	
    fstream ficheroEntrada;
    string nombre = filename;
    string frase;
	
    ficheroEntrada.open ( nombre.c_str() , ios::in);
    if (ficheroEntrada.is_open()) {
		
		string sobrante; 
		cout << nombre.c_str() << endl;
		
        while (! ficheroEntrada.eof() ) {
            getline (ficheroEntrada,frase);

            frase+= string("\n");
			sobrante+= frase;

			sobrante = procesarFrase(sobrante, largo, frecuencias);
			
        }
        ficheroEntrada.close();
        
        ofstream salidaGramas;
		salidaGramas.open ((nombre_salida + string ("datagramas")).c_str());
		ofstream salidaFrec;
		salidaFrec.open ((nombre_salida + string ("frecuencias")).c_str());
        
        
        for(vector<string>::iterator it = trigramas.begin(); it != trigramas.end(); it){
			salidaGramas << (*it);
			salidaFrec << ((*frecuencias)[*it]);
			++it;
			if(it != trigramas.end()){
				salidaGramas << ';';
				salidaFrec << ';';
			}
		}
               
        salidaGramas.close();
        salidaFrec.close();
		
    }
    
	
	else cout << "Fichero inexistente o faltan permisos para abrirlo" << endl;  
	
}
 
 
int main(int argc, char **argv){
	
	unordered_map<string, unsigned int> frecuencias;
//	unordered_map<string,int> frecuenciasGenerado;
	
	procesarEntrada(argv[2], atoi(argv[1]), string("entrada."), &frecuencias);
	printf("Se vacia el frecuencias\n");	
	printf("El tamaño actual es: %lu \n", frecuencias.size());
//	frecuencias.clear();	
	printf("El tamaño luego de vaciar es: %lu \n", frecuencias.size());

	for(vector<string>::iterator it = trigramas.begin(); it != trigramas.end(); ++it)
		frecuencias[*it]=0;
//		frecuenciasGenerado.insert(frecuenciasGenerado.begin(), pair<string,int>(*it, 0));
	
	printf("Serializar");
	int status, cantidadDeCaracteres;
//	status=scanf ("%i",&cantidadDeCaracteres);
	
	procesarEntrada(argv[3], atoi(argv[1]), string("generado."), &frecuencias);

	return 0;
}
