#include <iostream>
#include <math.h>
using namespace std;


/*
Programa para determinar las raices de una funcion f(x) mediante los metodos de falsa posicion, punto fijo o secante.

*/


void raizPorFalsaPosicion(float a,float b,float tol,int maximoIteraciones);
void raizPorPuntoFijo(float puntoFijo,float tol, int maximoIteraciones);
void raizPorSecante(float xactual, float xanterior, float tol, int maximoIteraciones);

float g(float x);
void imprimirMenuPrincipal();
float f(float x);
 
int main(int argc, char *argv[]) {
	
	int maximoIteraciones=0;
	float tol=0; // se ingresa ,va del 1-100
	float a,b;
	float puntoFijo;	// para met punto fijo 
	float xactual,xanterior; //para secante 
	
	int opcion=-1;
	
	while(opcion!=4){

	imprimirMenuPrincipal();
	cin>>opcion;
	cout<<endl;
	if(opcion==4){ // ACABAMOS EL PROGRAMA SI MARCÓ 4
			return 0; // END
	}
	
	
	cout<<"Ingrese la tolerancia en valores del 1 al 100 (porcentajes) "<<endl;	
	cin>>tol;
	
	cout<<"Ingrese la cantidad máxima de iteraciones"<<endl;	
	cin>>maximoIteraciones;
	
	if(opcion==1){
		
		do{
		cout<<"Ingrese el valor inferior"<<endl;
		cin>>a;
		cout<<"Ingrese el valor superior"<<endl;
		cin>>b;
		
		}while(  !(f(a)*f(b)<0)  ); // si fa * fb no es menor que 0, que repita el ingreso 
		
		
		
		
		raizPorFalsaPosicion(a,b,tol,maximoIteraciones);
		
		
	}
	
	if(opcion==2){
		cout<<"Ingrese numero cercano a la raiz"<<endl;
		cin>>puntoFijo;
		
		raizPorPuntoFijo(puntoFijo,tol,maximoIteraciones);
		
		
	}
	
	if(opcion==3){
		cout<<"Inserte el valor de x(i-1)"<<endl;
		cin>>xanterior;
		
		cout<<"Inserte el valor de x(i)"<<endl;
		cin>>xactual ;
		raizPorSecante(xactual, xanterior , tol,maximoIteraciones);
		
		
		
	}
	
	cout<<endl<<endl<<"Ingrese cualquier letra para continuar..."<<endl;
	char c; 
	cin>>c; 
	
	system("cls");
	
	}
	return 0;
}
//						rango inf, sup 
void raizPorFalsaPosicion(float xi,float xu,float tol,int maximoIteraciones){
	float xr,xant,errorRelativo;
		// VALIDAR QUE f(a)*f(b)<0
	
	int i=1;
	errorRelativo = 100;
	while(errorRelativo > tol  && i<=maximoIteraciones  ){
		
		xr = xu - (  f(xu)*(xi-xu)  )/(  f(xi)-f(xu)  );
	//	xi=  (  (f(b)*a)  -  (f(a)*b)  )/  (f(b)-f(a));
		
		if(f(xi)*f(xr)<0){//si tienen signos opuestos
			xu= xr;
		}else{ //si tienen signos iguales 
			xi = xr;
		}
		errorRelativo= abs(100*(xr- xant)/xr);
		cout<<"Iteracion "<<i<<"  x="<<xr<<" y el Error= "<<errorRelativo<<" %"<<endl;
		
		xant = xr;
		
		i++;
	}
	

}

void raizPorPuntoFijo(float puntoFijo,float tol, int maximoIteraciones){
	
	float xr,xanterior,a,b,errorRelativo;
	int i=1;
	errorRelativo=100;
	
	xanterior= puntoFijo;
	
	while(errorRelativo > tol  && i<=maximoIteraciones ){
		xr = g(xanterior);
		errorRelativo = 100*abs((xr-xanterior)/xr);
		
		cout<<"Iteracion "<<i<<" x="<<xr<<"  errorRelativo=  "<<errorRelativo<<" %"<<endl;
		xanterior=xr;
		i++;
	}
	
	
}

void raizPorSecante(float xactual, float xanterior, float tol , int maximoIteraciones){
	float errorP=100,xsiguiente;
	
	int i=0;
	//			1 
	while(errorP>tol && i<= (maximoIteraciones+1)  ){
		
		xsiguiente = xactual - f(xactual)*(  (xanterior- xactual)  /(  f(xanterior) - f(xactual)  )  );
		errorP = abs(100*(xactual - xanterior)/xactual);
		
		cout<<"Iteracion "<<i<<" x="<<xactual<<"  errorPorcentual= "<<errorP<<" %"<<endl;

		i++;
		xanterior = xactual;
		xactual= xsiguiente;
	}

}
 




	

// *************************** FUNCION A SACAR RAIZ ****************************** 	
float f(float x){
		
		//return exp(x)-4+x;

		//
		return sin(x) - x/2;
}
//FUNCION INVERSA QUE LA DE ARRIBA PARA EL METODO DE PUNTO FIJO 
float g(float x){
			
		//return log(4-x);
		return cos(x) - 0.5;
		
}		


 void imprimirMenuPrincipal(){
	cout<<" * * * * * * * * * * * * * * * * * MENU PRINCIPAL * * * * * * * * * * * * * * * * "<<endl;
	cout<<"Ingrese un número para seleccionar el método."<<endl;
	cout<<"1. Método Falsa Posicion"<<endl;
	cout<<"2. Método Punto fijo"<<endl;
	cout<<"3. Metodo de la Secante" <<endl;
	cout<<"4. Salir" <<endl;
	cout<<"Ingrese su opcion: "<<endl;
	
}

