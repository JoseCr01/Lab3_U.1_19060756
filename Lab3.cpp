/********************************************************/
 // Nombre del archivo:Lab3.c                            /         
 // Autor:José Cruz Armendariz                           /
 // Asignatura: Arquitectura de Prog. para Hardware      /
 // Docente:Alfredo Chacon                               /
 // fecha: 05/10/2022                                    /
 /*******************************************************/
 
#include <iostream>
#include <stdlib.h>

using namespace std;

/*Clase*/
class Adc{
	
	/*Atributos*/
	private:
		float Volt;
		double Bits;
		string Canal;
		static int Rs;
		static float Frec;
	/*Metodos*/
	public:
		Adc(){};
		void Canales();
		void Leer();
		void MuestraDatos();
		static void CapturaDatos();
		
};

void Adc::Leer(){
	/*Lectura y validacion de los datos*/
  do{
    cout<<"Introduzca el valor del voltaje(0-3.3) AN"<<Canal<<":";
    cin>>Volt;
    cout<< "\n";
    if(Volt<0 || Volt>3.3){
      cout<<"El valor de voltaje es invalido"<<endl;
    }
    
  }while (Volt<0 || Volt>3.3);
  
  /*Resolucion de 8 bits*/
  if(Rs == 8){
    Bits = (Volt*255)/3.3;
  }
    /*Resolucion de 10 bits*/
  if(Rs == 10){
  	Bits = (Volt*1023)/3.3;
  }
    /*Resolucion de 12 bits*/
   if(Rs == 12){
  	Bits = (Volt*4095)/3.3;
  }
}

void Adc::CapturaDatos(){
	/*Validacion de datos*/
	 do{
	  cout<<"Introduzca los bits de la resolucion(8,10,12): ";
	  cin>> Rs;
	  cout<< "\n";
	  
    if(Rs != 8 && Rs != 10 && Rs !=12)
    {
      cout<< "Los bits no son validos"<<endl;
    }
  }while(Rs!= 8 && Rs!= 10 && Rs!=12);
  
	cout<<"Introduzca el valor de la frecuencia en Hz: ";
	cin>> Frec;
    cout<< "\n";
	
}

void Adc::Canales(){
	cout<< "Introduzca el valor del canal AN que se usara (1-32):";
  	cin>> Canal;
  	cout<< "\n";
}

void Adc::MuestraDatos(){
	cout<<"El canal AN"<<Canal<<" tiene una conversion de: "<<Bits<<endl;
}

/*Inicializacion de las variables static*/
float Adc:: Frec=0;
int Adc:: Rs=0;

/*Funcion main*/
int main(){
	
	/*Variables locales*/
	int i,canales;
	/*Portada*/
	cout<<"             Laboratorio 3                  "<<endl;
	cout<<"     Jose Cruz Armendariz 19060756          "<<endl;
	cout<<"Materia: Arquitectura de Prog. para Hardware"<<endl;
	cout<<"       Docente: Alfredo Chacon              "<<endl;
	cout<<"   Instituto Tecnologico de Chihuahua       "<<endl;
	cout<<"        Configuracion de un ADC             "<<endl;
	
	Adc::CapturaDatos();
    cout<< "Introduzca el numero de canales: ";
    cin>>canales;
    cout<< "\n";
    
    /*Ciclos for para la lectura de datos*/
    Adc Leer[canales];
    for(int i=0; i<canales; i++){
		Leer[i].Canales();
	}
	for(int i=0; i<canales; i++){
		Leer[i].Leer();
	}
	for(int i=0; i<canales; i++){
		Leer[i].MuestraDatos();
	}
	return 0;
}
