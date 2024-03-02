#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<graphics.h>

struct nodo { //estructura de 5 miembros
    int info; //entero que guarda alg�n tipo de informaci�n relevante para el nodo.
    struct nodo *sig;   //puntero
	struct nodo *ant;  //puntero 
    struct nodo *abajo; //puntero
    struct nodo *arriba;  //puntero
    struct nodo *enfrente; //puntero
    struct nodo *atras; //puntero
};

struct nodo *raiz1=NULL,*raiz2=NULL,*raiz3=NULL; //Declara tres punteros y los iniciamos en NULL
void imprimir();	//Esta funci�n ser� utilizada para imprimir el contenido del cubo en la consola.
void crearcubo(); 	//Esta funci�n ser� utilizada para crear la estructura de datos del cubo y asignar los punteros
int sacarDato(int fila, int columna, int cara); //Esta funci�n ser� utilizada para obtener el valor almacenado en una celda espec�fica del cubo.
int sumarColumna(int columna);	//Esta funci�n ser� utilizada para sumar los valores de una columna espec�fica del cubo.
int sumarFila(int fila);  // Esta funci�n ser� utilizada para sumar los valores de una fila espec�fica del cubo.
int sumarCara(int cara);	//Esta funci�n ser� utilizada para sumar los valores de una cara espec�fica del cubo.
void grafico();  //Esta funci�n ser� utilizada para imprimir una representaci�n gr�fica del cubo en la consola.
void cara(int n);  //Esta funci�n ser� utilizada para imprimir una cara espec�fica del cubo en la consola.

int main(){
	int opcion, suma = 0, fila, columna,cara;
	
		printf("Elija una de las siguientes opciones\n (1)Sumar una fila)\n (2)Sumar columnas)\n (3)Sumar Renglones)\n (4)Sumar caras)\n(5)Ver Cubo");
    	scanf("%d", &opcion);  
	    switch (opcion){
            case 1:{
			        printf("Ingrese el n�mero de cara que desea sumar:\n");
			        scanf("%i", &cara);
                   	printf("Ingrese el n�mero de fila que desea sumar:\n");
        			scanf("%i", &fila);
        			
    	    			struct nodo *reco=raiz1; 
							for(int x=1;x<columna;x++){
								reco=reco->sig;		
							}
							return reco->info; 
						
						struct nodo *reco1=raiz1;
							for(int x=1;x<fila;x++){
								reco1=reco1->arriba; 
							}
							return reco1->info; 
						
        			
					for (int x = 1; x <= 5; x++) { 
            			suma+= raiz1->infog;
        			}													
    		}														
                break;

            }

            /*case 2:{

                break;

            }
            case 3:{

                break;

            }
			default: {

            }
*/
      }
	
	
	
     
    else if (opcion == 2) {
        printf("Ingrese el n�mero de columna que desea sumar:\n");
        scanf("%i", &columna);
        printf("Ingrese el n�mero de cara que desea sumar:\n");
        scanf("%i", &cara);
        for (int x = 1; x <= 5; x++) {  //For que se repite 5 veces
            suma = suma + sumarColumna(columna)+ x + sumarCara(cara);  //En cada iteraci�n del ciclo, se realiza una operaci�n 
        }																//que suma el resultado de las funciones sumarColumna y sumarCara 
    }																	//con el valor de x y el valor actual de suma, y asigna el resultado a la variable suma.
    else if (opcion == 3) {
    	printf("Ingrese el n�mero de fila que desea sumar:\n");
        scanf("%i", &fila);
        printf("Ingrese el n�mero de columna que desea sumar:\n");
        scanf("%i", &columna);
        for (int x = 1; x <= 5; x++) {//For que se repite 5 veces
            	suma=suma+sumarColumna(columna)+sumarFila(fila)+ x; 	//En cada iteraci�n del ciclo, se realiza una operaci�n 
        }																//que suma el resultado de las funciones sumarColumna y sumarFila 
    }																	//con el valor de x y el valor actual de suma, y asigna el resultado a la variable suma.
    else if (opcion == 4) {
        printf("Ingrese el n�mero de cara que desea sumar:\n");
        scanf("%i", &cara);
        for (int x = 1; x <= 5; x++) { //nicia un ciclo for que se repetir� cinco veces, con la variable x inicializada en 1.
            for (int y = 1; y <= 5; y++) { //Inicia un ciclo for anidado que tambi�n se repetir� cinco veces, con la variable y inicializada en 1
            	suma=suma+ x + y + sumarCara(cara); //En cada iteraci�n del ciclo anidado, se realiza una operaci�n que suma el valor actual de suma 
        	}										//con el valor de x, el valor de y, y el resultado de la funci�n sumarCara con el argumento cara.
        }											// El resultado de la suma se asigna de nuevo a la variable suma.        
    }else if (opcion == 5) {
        crearcubo();  //Llama a la funci�n crearcubo() para crear un nuevo cubo.
		imprimir();		//Llama a la funci�n imprimir() para imprimir en la consola los valores de cada nodo del cubo.
		grafico();		//Llama a la funci�n grafico() para imprimir en la consola una representaci�n gr�fica del cubo.
	
    }
    else {
        printf("La opci�n que seleccion� no es v�lida.\n");
    }
    
    printf("La suma es: %i\n", suma);
    
}
int sumarColumna(int columna){
	struct nodo *reco=raiz1; //Declara e inicializa una variable llamada reco que apunta a la misma direcci�n de memoria que la variable raiz1
	for(int x=1;x<columna;x++){ //Inicia un ciclo for que se repetir� columna-1 veces, con la variable x inicializada en 1.
		reco=reco->sig;		//se mueve a trav�s del cubo a la siguiente columna al derecha, asignando el puntero sig del nodo actual a la variable reco.
		}
		return reco->info; //Una vez que se llega a la columna deseada, la funci�n devuelve el valor de info del nodo actual
}
int sumarFila(int fila){
	struct nodo *reco=raiz1; //Declara e inicializa una variable llamada reco que apunta a la misma direcci�n de memoria que la variable raiz1
	for(int x=1;x<fila;x++){ //Inicia un ciclo for que se repetir� fila-1 veces, con la variable x inicializada en 1.
		reco=reco->arriba; //se mueve a trav�s del cubo a la siguiente fila al derecha, asignando el puntero sig del nodo actual a la variable reco.
		}
		return reco->info; //Una vez que se llega a la fila deseada, la funci�n devuelve el valor de info del nodo actual
}
int sumarCara(int cara){
	struct nodo *reco=raiz1; //Declara e inicializa una variable llamada reco que apunta a la misma direcci�n de memoria que la variable raiz1
	for(int x=1;x<cara;x++){ //Inicia un ciclo for que se repetir� cara-1 veces, con la variable x inicializada en 1.
		reco=reco->abajo; //se mueve a trav�s del cubo a la siguiente cara al derecha, asignando el puntero sig del nodo actual a la variable reco.
		}
		return reco->info; //Una vez que se llega a la cara deseada, la funci�n devuelve el valor de info del nodo actual
}
int sacarDato(int fila, int columna, int cara){ //que toma tres par�metros de entrada: fila, columna y cara, que son enteros que representan la posici�n del nodo que se desea recuperar del cubo.
	struct nodo *reco=raiz1; //Declara e inicializa una variable de tipo struct nodo llamada reco que apunta a la misma direcci�n de memoria que la variable raiz1.
	for(int x=1;x<cara;x++){ //Inicia un ciclo for que se repetir� cara-1 veces, con la variable x inicializada en 1.
		reco=reco->abajo; //En cada iteraci�n del ciclo, se mueve a trav�s del cubo a la siguiente cara, asignando el puntero adelante del nodo actual a la variable reco.
		}
	for(int x=1;x<fila;x++){//Inicia otro ciclo for que se repetir� fila-1 veces, con la variable x inicializada en 1.
		reco=reco->arriba; //En cada iteraci�n del ciclo, se mueve a trav�s del cubo al nodo que est� encima, asignando el puntero arriba del nodo actual a la variable reco.
		}
	for(int x=1;x<columna;x++){ //Inicia otro ciclo for que se repetir� columna-1 veces, con la variable x inicializada en 1.
		reco=reco->sig;// En cada iteraci�n del ciclo, se mueve a trav�s del cubo al siguiente nodo a la derecha, asignando el puntero sig del nodo actual a la variable reco.
		}
	return reco->info;// Una vez que se llega al nodo deseado, la funci�n devuelve el valor de info del nodo actual, que es el valor almacenado en la posici�n 
}
void imprimir() {
    struct nodo *reco = raiz1; //Declara e inicializa una variable de tipo struct nodo llamada reco que apunta a la misma direcci�n de memoria que la variable raiz1

    while (reco != NULL) { //Inicia un ciclo while que se repetir� mientras el puntero reco no sea NULL.
        struct nodo *temp = reco; //Declara e inicializa una variable de tipo struct nodo llamada temp que apunta a la misma direcci�n de memoria que la variable reco.
        while (temp != NULL) { //Inicia otro ciclo while que se repetir� mientras el puntero temp no sea NULL.
            printf("%i ", temp->info);//En cada iteraci�n del ciclo, se imprime el valor de info del nodo actual.
            temp = temp->sig;//En cada iteraci�n del ciclo, se mueve a trav�s del cubo al siguiente nodo a la derecha, asignando el puntero sig del nodo actual a la variable temp.
        }
        reco = reco->arriba;//Al final del ciclo interno, se mueve a trav�s del cubo al nodo que est� encima, asignando el puntero arriba del nodo actual a la variable reco.
        printf("\n"); // Imprime una nueva l�nea despu�s de imprimir todos los nodos de la fila actual.
    }
}
void crearcubo(){
		struct nodo *nuevo,*aux;
		// Se declara una variable de tipo struct nodo para representar un nuevo nodo, y un puntero auxiliar.
    // Este puntero se utilizar� para apuntar al �ltimo nodo creado y as� poder enlazarlo con el siguiente.
    // La idea general es ir recorriendo el cubo de manera ordenada, y para ello se necesitan tres bucles for anidados.
    // El primer bucle recorre las caras del cubo, el segundo las filas y el tercero las columnas.
	for(int x=1;x<6;x++){
		for(int y=1;y<5;y++){
			for(int z=1;z<5;z++){
				// Se verifica si el cubo est� vac�o, es decir, si no hay nodos a�n.
				if (raiz1 == NULL){
					 // Se crea un nuevo nodo para la ra�z del cubo.
				nuevo = (struct nodo*)malloc(sizeof(struct nodo));
				nuevo->arriba=NULL;
				nuevo->abajo=NULL;
				nuevo->atras=NULL;
				nuevo->enfrente=NULL;
				nuevo->info=5;
				nuevo->sig=NULL;
			    raiz1 = nuevo;
			    raiz2=raiz1;
			    raiz3=raiz2;
				aux=raiz3;				
				nuevo = (struct nodo*)malloc(sizeof(struct nodo));
				nuevo->info=x+y+z;
				nuevo->sig=NULL;
			    aux->sig=nuevo;
			    aux=aux->sig;	
			    // Si el cubo est� vac�o, se agrega el primer nodo. Este nodo se ubica en la primera posici�n
                    // del cubo (esquina inferior izquierda) y se le asigna el valor 5.
                    // Adem�s, se inicializan los punteros raiz1, raiz2, raiz3 y aux para poder continuar la creaci�n del cubo.
                    // El puntero aux se inicializa con raiz3 porque a�n no hay columnas creadas.
                }
			 else{
		    	 // Si el cubo ya tiene nodos, se sigue creando la estructura.
		    	nuevo = (struct nodo*)malloc(sizeof(struct nodo));
				nuevo->info=x+y+z;
				nuevo->sig=NULL;
			    aux->sig=nuevo;
			    aux=aux->sig;
	    	}
			    }
			    // Cuando se han agregado todas las columnas de una fila, se agrega un nuevo nodo arriba del �ltimo nodo creado,
            // que representa la suma de los valores de la fila y se inicializa el puntero aux con el nuevo nodo.

				nuevo = (struct nodo*)malloc(sizeof(struct nodo));
				nuevo->info=x+y;
				nuevo->arriba=NULL;
				raiz3->arriba=nuevo;
			    raiz3=raiz3->arriba;
				aux=raiz3;
				// Si la fila es la �ltima, se agregan cuatro nodos m�s para cerrar la cara del cubo.
				if(y==4){
				    for(int w=1;w<5;w++){
				        nuevo = (struct nodo*)malloc(sizeof(struct nodo));
				nuevo->info=x+y+w;
				nuevo->sig=NULL;
			    aux->sig=nuevo;
			    aux=aux->sig;
				    }
				    
				}// Cuando se han agregado todas las filas de una cara, se agrega un nuevo nodo adelante del �ltimo nodo creado,
        // que representa el n�mero de la cara. Adem�s, se inicializan los punteros raiz2, raiz3 y aux con el nuevo nodo.
				
		}
		if(x==5){}else{
		nuevo = (struct nodo*)malloc(sizeof(struct nodo));
		nuevo->info=x;
		nuevo->abajo=NULL;
		raiz2->abajo=nuevo;
	    raiz2=raiz2->abajo;
		raiz3=raiz2;
		aux=raiz3;
		}
	}
}
void grafico() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");//Se toma la variable gd para almacenar la gm para especificar y "char*"  puntero para especificar la ruta de acceso a la liberia
    initwindow(1800, 900);
    for(int x = 1; x < 6; x++) {
        cara(x);
    }
    setcolor(WHITE);
    line(330, 200, 300, 200);
    line(350, 180, 350, 150);
    line(340, 190, 315, 175);
    getch();
}

void cara(int n){
    char resultado[20]; //definimos la capacidad para almacenar hasta 20 caracteres.
    setfillstyle(1,n); //relleno de coloeres que es la n y el numero de 1 es el color solido 
    setbkcolor(n); //color de fondo
    for(int x=1;x<6;x++){ //Dibujar cinco columnas de c�rculos en cada fila. La variable
        // Para dibujar cinco columnas de c�rculos en cada fila
        for(int y=1; y<6; y++){ //Dibujar en cada columna de la fila actual.
            int xPos = 200 + (100 * x) + (35 * n); // calcula la posici�n horizontal del c�rculo actual en la fila utilizando la variable x y el argumento n. 
            int yPos = 200 + (100 * y) - (35 * n);// calcula la posici�n vertical del c�rculo actual en la columna utilizando la variable y y el argumento n. 
            // Cada c�rculo ser� un cuadrado
            bar(xPos, yPos, xPos + 20, yPos + 20); //Esta l�nea dibuja un cuadrado de tama�o 20 x 20 en las coordenadas xPos y yPos
            gcvt(sacarDato(y, x, n), 6, resultado); //convierte un n�mero decimal obtenido de la funci�n sacarDato y lo almacena en resultado
            outtextxy(xPos - 10, yPos - 10, resultado); //muestra el valor de resultado en la posici�n (xPos - 10, yPos - 10) utilizando la funci�n outtextxy.
        }
    }
}

