#include <fstream>
#include <ctime>
#include <stdio.h>
#include "verificadorDeBits.h"
#include "coder/encoder.h"
#include "coder/decoder.h"

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
    std::ofstream* os, unsigned long long* output_bytes, PPM* p) {
  Encoder e(os, p);
  verificadorDeBits unVerificador;
  unsigned long long percent = 1 + (input_bytes / 100);
  
  for (unsigned long long pos = 0; pos < input_bytes; ++pos) {
    char c = is->get();
    unVerificador.insert(c);
    for (int j = 7; j >= 0; --j) {
      e.Encode((c>>j)&1);
    }
    
    if (pos % percent == 0) {
		printf("\rprogress: %lld%%", pos / percent);
		fflush(stdout);
    }
  }
  e.Flush();
  
  printf("\n GENERANDO!!! \n");
	int count = 0;
	int resultado = 0;
	int count32= 0;
	int resultado32 = 0;
	unsigned int xMid;
	e.generando = true;
	//std::string ventanaCotx;
	//std::string ventanaCotxAux;
	unsigned int finalNum;
	e.manager_->bit_context_ = 1;
	for (int i = 0; i < 100008; i++){
		finalNum = 0;
		
		e.p = e.Discretize(e.p_->Predict());
		
		xMid = e.X1 + ((e.X2 - e.X1) >> 16) * e.p + (((e.X2 - e.X1) & 0xffff) * e.p >> 16);
		finalNum = rand()%(e.X2 - e.X1)+e.X1;
	
		resultado = resultado<<1;
		resultado32 = resultado32<<1;
		count++;
		count32++;
		if (finalNum<=xMid){
			resultado++;
			resultado32++;
			//e.Encode(1);
			
			if(unVerificador.verificar(resultado32,count32))
				e.Encode(1);
			else{
				resultado32--;
				resultado--;
				e.Encode(0);
			
			}
		}else{
			//e.Encode(0);
			
			if(unVerificador.verificar(resultado32,count32))
				e.Encode(0);
			else{
				resultado++;
				resultado32++;
				e.Encode(1);
			
			}
		}
		
		if (count==8){
			//printf("\n");
			//ventanaCotx+= resultado;
			char charAImprimir = resultado;
			printf("%c",charAImprimir);
			resultado = 0;
			count = 0;
		}
		if(count32== NUMERODEBITS){
			count32 = 0;
			resultado32 = 0;
		}
		

	}
  *output_bytes = os->tellp();
}

void Decompress(unsigned long long output_length, std::ifstream* is,
                std::ofstream* os, PPM* p) {
  Decoder d(is, p);
  unsigned long long percent = 1 + (output_length / 100);
  for(unsigned long long pos = 0; pos < output_length; ++pos) {
    int byte = 1;
    while (byte < 256) {
      byte += byte + d.Decode();
    }
    os->put(byte);
    if (pos % percent == 0) {
      printf("\rprogress: %lld%%", pos / percent);
      fflush(stdout);
    }
  }
}

int fail() {
  printf("With preprocessing:\n");
  printf("    compress:   cmix -c [dictionary] [input] [output]\n");
  printf("    decompress: cmix -d [dictionary] [input] [output]\n");
  printf("Without preprocessing:\n");
  printf("    compress:   cmix -c [input] [output]\n");
  printf("    decompress: cmix -d [input] [output]\n");
  return -1;
}

int main(int argc, char* argv[]) {
  if (argc < 4 || argc > 5 || argv[1][0] != '-' ||
      (argv[1][1] != 'c' && argv[1][1] != 'd')) {
    return fail();
  }
  bool compressing = false;
  if (argv[1][1] == 'c') compressing = true;

  clock_t start = clock();

  bool enable_preprocess = false;
  std::string input_path = argv[2];
  std::string output_path = argv[3];
  /*
  FILE* dictionary = NULL;
  if (argc == 5) {
    enable_preprocess = true;
    dictionary = fopen(argv[2], "rb");
    if (!dictionary) return fail();
    input_path = argv[3];
    output_path = argv[4];
  }
  */
  std::string temp_path = output_path;
  if (enable_preprocess) temp_path += ".cmix.temp";

  unsigned long long input_bytes = 0, output_bytes = 0;

  PPM * p = new PPM(7, 1, 100, 80);

  if (compressing) {
    
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
    
  } else {
    std::ifstream data_in(input_path, std::ios::in | std::ios::binary);
    if (!data_in.is_open()) return fail();
    std::ofstream temp_out(temp_path, std::ios::out | std::ios::binary);
    if (!temp_out.is_open()) return fail();

    data_in.seekg(0, std::ios::end);
    input_bytes = data_in.tellg();
    data_in.seekg(0, std::ios::beg);
    
    ReadHeader(&data_in, &output_bytes);
    Decompress(output_bytes, &data_in, &temp_out, p);
    data_in.close();
    temp_out.close();


  }
  
  printf("\r%lld bytes -> %lld bytes in %1.2f s.\n",
      input_bytes, output_bytes,
      ((double)clock() - start) / CLOCKS_PER_SEC);

  if (compressing) {
    double cross_entropy = output_bytes;
    cross_entropy /= input_bytes;
    cross_entropy *= 8;
    printf("cross entropy: %.3f\n", cross_entropy);
  }

  return 0;
}
