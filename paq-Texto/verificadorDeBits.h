#define NUMERODEBITS 8 //Multiplo de 8... por favor...
class node
{	
	public:
		bool exist;
		node *left;
		node *right;
		void destruir();
		node();
};
class verificadorDeBits
{
	private:
		node* raiz;
		node* actualNode;
		int cantidadProcesada;
		std::string verificados;
	
	public:
		
		verificadorDeBits();
		void insert(int);
		bool verificar(int, int);
		~verificadorDeBits();
};


node::node(){
	this->exist = false;
}

void node::destruir(){
	if(this->exist){
		this->right->destruir();
		this->left->destruir();
		delete this;
	}
	else
		delete this;
	
}

verificadorDeBits::verificadorDeBits(){
	this->raiz = new node;
	this->raiz->exist = true;
	this->raiz->left = new node;
	this->raiz->right = new node;	
	cantidadProcesada = 0;
	this->verificados = "";
}

void verificadorDeBits::insert(int valor){
	if((cantidadProcesada%(NUMERODEBITS/8)) == 0)
		this->actualNode = this->raiz;
	this->cantidadProcesada++;
	for (int i=7; i>=0; i--){
		
		if((valor>>i)&1)
			this->actualNode = actualNode->right;
		else
			this->actualNode = actualNode->left;
			
		if(!this->actualNode->exist){
			this->actualNode->exist = true;
			this->actualNode->left = new node;
			this->actualNode->right = new node;
		}
		
	}

}
bool verificadorDeBits::verificar(int valor, int rango){
	node* auxNode; 
	auxNode = this->raiz;
	//std::cout << "Verificador Valor: " << valor << "  rango: " << rango <<'\n';

	int contador = 0;
	int valorTransformado = valor<<(NUMERODEBITS-rango);
	//std::cout << "Verificador Transformado: " << valorTransformado <<'\n';
	
	bool existe = true;
	
	while((contador < rango)&&(existe)){
		int i = NUMERODEBITS - 1 - contador;
		if((valorTransformado>>i)&1){
			auxNode = auxNode->right;
		}
		else{
			auxNode = auxNode->left;
		}
		existe = auxNode->exist;
		contador++;
	}
	return existe;
}


verificadorDeBits::~verificadorDeBits(){
	this->raiz->destruir();
}





