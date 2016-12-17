#include <fstream>
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "coder/encoder.h"																																																																																																																																																																																																																																																																																																																	
#include "coder/decoder.h"
#include <unistd.h>

void WriteHeader(unsigned long long length, std::ofstream* os) {
  for (int i = 4; i >= 0; --i) {
    char c = length >> (8*i);
    os->put(c);
  }
}

void ReadHeader(std::ifstream* is, unsigned long long* length) {
  *length = 0;
  for (int i = 0; i < 5; ++i) {
    *length <<= 8;
    *length += (unsigned char)(is->get());
  }
}

void Compress(unsigned long long input_bytes, std::ifstream* is,

  std::ofstream* os, unsigned long long* output_bytes, PAQ8L* p) {
  
  Encoder e(os, p);

  unsigned long long percent = 1 + (input_bytes / 100);
  
  for (unsigned long long pos = 0; pos < input_bytes; ++pos) {
    char c = is->get();
    for (int j = 7; j >= 0; --j) {
      e.Encode((c>>j)&1);
    }
    
    if (pos % percent == 0) {
		printf("\rprogress: %lld%%", (pos / percent)+1);
		fflush(stdout);
    }
    
  }
  e.Flush();
	int count = 0;
	int resultado = 0;
	unsigned int xMid, x1Bis, x2Bis;
	unsigned int puntoMedio;
	float longitud;	

	e.generando = true;
	unsigned int finalNum;

	//printf("Congelando proceso de compresion \n");
	int numeroPID=getpid();		
	std::string s = std::to_string(numeroPID);

	std::string comando = "cr_checkpoint --file CheckpointGoT --term ";

	comando+=s;

	//system(comando.c_str());

	int cantidadDeCaracteres = 1000;
	float temperatura = 1.0;
	int status;	
	printf("\nIngresar la cantidad de letras que quiere generar \n");
	status=scanf ("%i",&cantidadDeCaracteres);

	printf("Ingresar la temperatura entre 0 y 1 \n");	
	status=scanf ("%f",&temperatura);

	printf("Ingresar el nombre del archivo de salida \n");	

	std::string nombreArchivo;
	std::cin >> nombreArchivo;

	std::ofstream outfile(nombreArchivo, std::ofstream::binary);
	srand(time(NULL));

	for (int i = 0; i < 8* cantidadDeCaracteres; i++){
		finalNum = 0;
		
		e.p = e.Discretize(e.p_->Predict());
		
		xMid = e.X1 + ((e.X2 - e.X1) >> 16) * e.p + (((e.X2 - e.X1) & 0xffff) * e.p >> 16);
		
		puntoMedio = (e.X2 - e.X1) / 2;
		puntoMedio += e.X1;

		longitud = (e.X2 - e.X1) / 2;
		
		x2Bis = e.X2 - (unsigned int)((1.0-temperatura)*longitud);
		x1Bis = e.X1 + (unsigned int)((1.0-temperatura)*longitud);

		finalNum = rand()%(x2Bis - x1Bis)+ x1Bis;

		resultado = resultado<<1;
		count++;
		if (finalNum<=xMid){
			resultado++;
			e.Encode(1);
			
		}else
			e.Encode(0);
		
		if (count==8){
			char charAImprimir = resultado;
			outfile.put(charAImprimir);
			printf("%c",charAImprimir);
			resultado = 0;
			count = 0;
		}
		

	}
  *output_bytes = os->tellp();
}

void Decompress(unsigned long long output_length, std::ifstream* is,
                std::ofstream* os, PAQ8L* p) {
  Decoder d(is, p);
  unsigned long long percent = 1 + (output_length / 100);
  for(unsigned long long pos = 0; pos < output_length; ++pos) {
    int byte = 1;
    while (byte < 256) {
      byte += byte + d.Decode();
    }
    os->put(byte);
    if (pos % percent == 0) {
      fflush(stdout);
    }
  }
}

int fail() {

  printf("To generate:   PAQ -g [input]\n");
  return -1;
}

int main(int argc, char* argv[]) {
	if (argc < 2 || argc > 4 || argv[1][0] != '-' || (argv[1][1] != 'g'))
		return fail();
	
	bool compressing = false;
	if (argv[1][1] == 'g') compressing = true;

	clock_t start = clock();

	bool enable_preprocess = false;
	std::string input_path = argv[2];
	std::string output_path = "/tmp/compress.paq";

	std::string temp_path = output_path;
	if (enable_preprocess) temp_path += ".cmix.temp";

	unsigned long long input_bytes = 0, output_bytes = 0;

	PAQ8L * p = new PAQ8L(10);


    
	temp_path = input_path;

	std::ifstream temp_in(temp_path, std::ios::in | std::ios::binary);
	if (!temp_in.is_open()) return fail();
	std::ofstream data_out(output_path, std::ios::out | std::ios::binary);
	if (!data_out.is_open()) return fail();

	temp_in.seekg(0, std::ios::end);
	unsigned long long temp_bytes = temp_in.tellg();
	if (!enable_preprocess) input_bytes = temp_bytes;
	temp_in.seekg(0, std::ios::beg);

	WriteHeader(temp_bytes, &data_out);
	Compress(temp_bytes, &temp_in, &data_out, &output_bytes, p);
	temp_in.close();
	data_out.close();

	double cross_entropy = output_bytes;
	cross_entropy /= input_bytes;
	cross_entropy *= 8;

	return 0;
}
