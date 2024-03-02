#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<graphics.h>

struct nodo { //estructura de 5 miembros
    int info; //entero que guarda algún tipo de información relevante para el nodo.
    struct nodo *sig;   //puntero
	struct nodo *ant;  //puntero 
    struct nodo *abajo; //puntero
    struct nodo *arriba;  //puntero
    struct nodo *enfrente; //puntero
    struct nodo *atras; //puntero
};

struct nodo *raiz1=NULL,*raiz2=NULL,*raiz3=NULL; //Declara tres punteros y los iniciamos en NULL
void imprimir();	//Esta función será utilizada para imprimir el contenido del cubo en la consola.
void crearcubo(); 	//Esta función será utilizada para crear la estructura de datos del cubo y asignar los punteros
int sacarDato(int fila, int columna, int cara); //Esta función será utilizada para obtener el valor almacenado en una celda específica del cubo.
int sumarColumna(int columna);	//Esta función será utilizada para sumar los valores de una columna específica del cubo.
int sumarFila(int fila);  // Esta función será utilizada para sumar los valores de una fila específica del cubo.
int sumarCara(int cara);	//Esta función será utilizada para sumar los valores de una cara específica del cubo.
void grafico();  //Esta función será utilizada para imprimir una representación gráfica del cubo en la consola.
void cara(int n);  //Esta función será utilizada para imprimir una cara específica del cubo en la consola.

int main(){
	int opcion, suma = 0, fila, columna,cara;
	
		printf("Elija una de las siguientes opciones\n (1)Sumar una fila)\n (2)Sumar columnas)\n (3)Sumar Renglones)\n (4)Sumar caras)\n(5)Ver Cubo");
    	scanf("%d", &opcion);  
	    switch (opcion){
            case 1:{
			        printf("Ingrese el número de cara que desea sumar:\n");
			        scanf("%i", &cara);
                   	printf("Ingrese el número de fila que desea sumar:\n");
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
        printf("Ingrese el número de columna que desea sumar:\n");
        scanf("%i", &columna);
        printf("Ingrese el número de cara que desea sumar:\n");
        scanf("%i", &cara);
        for (int x = 1; x <= 5; x++) {  //For que se repite 5 veces
            suma = suma + sumarColumna(columna)+ x + sumarCara(cara);  //En cada iteración del ciclo, se realiza una operación 
        }																//que suma el resultado de las funciones sumarColumna y sumarCara 
    }																	//con el valor de x y el valor actual de suma, y asigna el resultado a la variable suma.
    else if (opcion == 3) {
    	printf("Ingrese el número de fila que desea sumar:\n");
        scanf("%i", &fila);
        printf("Ingrese el número de columna que desea sumar:\n");
        scanf("%i", &columna);
        for (int x = 1; x <= 5; x++) {//For que se repite 5 veces
            	suma=suma+sumarColumna(columna)+sumarFila(fila)+ x; 	//En cada iteración del ciclo, se realiza una operación 
        }																//que suma el resultado de las funciones sumarColumna y sumarFila 
    }																	//con el valor de x y el valor actual de suma, y asigna el resultado a la variable suma.
    else if (opcion == 4) {
        printf("Ingrese el número de cara que desea sumar:\n");
        scanf("%i", &cara);
        for (int x = 1; x <= 5; x++) { //nicia un ciclo for que se repetirá cinco veces, con la variable x inicializada en 1.
            for (int y = 1; y <= 5; y++) { //Inicia un ciclo for anidado que también se repetirá cinco veces, con la variable y inicializada en 1
            	suma=suma+ x + y + sumarCara(cara); //En cada iteración del ciclo anidado, se realiza una operación que suma el valor actual de suma 
        	}										//con el valor de x, el valor de y, y el resultado de la función sumarCara con el argumento cara.
        }											// El resultado de la suma se asigna de nuevo a la variable suma.        
    }else if (opcion == 5) {
        crearcubo();  //Llama a la función crearcubo() para crear un nuevo cubo.
		imprimir();		//Llama a la función imprimir() para imprimir en la consola los valores de cada nodo del cubo.
		grafico();		//Llama a la función grafico() para imprimir en la consola una representación gráfica del cubo.
	
    }
    else {
        printf("La opción que seleccionó no es válida.\n");
    }
    
    printf("La suma es: %i\n", suma);
    
}
int sumarColumna(int columna){
	struct nodo *reco=raiz1; //Declara e inicializa una variable llamada reco que apunta a la misma dirección de memoria que la variable raiz1
	for(int x=1;x<columna;x++){ //Inicia un ciclo for que se repetirá columna-1 veces, con la variable x inicializada en 1.
		reco=reco->sig;		//se mueve a través del cubo a la siguiente columna al derecha, asignando el puntero sig del nodo actual a la variable reco.
		}
		return reco->info; //Una vez que se llega a la columna deseada, la función devuelve el valor de info del nodo actual
}
int sumarFila(int fila){
	struct nodo *reco=raiz1; //Declara e inicializa una variable llamada reco que apunta a la misma dirección de memoria que la variable raiz1
	for(int x=1;x<fila;x++){ //Inicia un ciclo for que se repetirá fila-1 veces, con la variable x inicializada en 1.
		reco=reco->arriba; //se mueve a través del cubo a la siguiente fila al derecha, asignando el puntero sig del nodo actual a la variable reco.
		}
		return reco->info; //Una vez que se llega a la fila deseada, la función devuelve el valor de info del nodo actual
}
int sumarCara(int cara){
	struct nodo *reco=raiz1; //Declara e inicializa una variable llamada reco que apunta a la misma dirección de memoria que la variable raiz1
	for(int x=1;x<cara;x++){ //Inicia un ciclo for que se repetirá cara-1 veces, con la variable x inicializada en 1.
		reco=reco->abajo; //se mueve a través del cubo a la siguiente cara al derecha, asignando el puntero sig del nodo actual a la variable reco.
		}
		return reco->info; //Una vez que se llega a la cara deseada, la función devuelve el valor de info del nodo actual
}
int sacarDato(int fila, int columna, int cara){ //que toma tres parámetros de entrada: fila, columna y cara, que son enteros que representan la posición del nodo que se desea recuperar del cubo.
	struct nodo *reco=raiz1; //Declara e inicializa una variable de tipo struct nodo llamada reco que apunta a la misma dirección de memoria que la variable raiz1.
	for(int x=1;x<cara;x++){ //Inicia un ciclo for que se repetirá cara-1 veces, con la variable x inicializada en 1.
		reco=reco->abajo; //En cada iteración del ciclo, se mueve a través del cubo a la siguiente cara, asignando el puntero adelante del nodo actual a la variable reco.
		}
	for(int x=1;x<fila;x++){//Inicia otro ciclo for que se repetirá fila-1 veces, con la variable x inicializada en 1.
		reco=reco->arriba; //En cada iteración del ciclo, se mueve a través del cubo al nodo que está encima, asignando el puntero arriba del nodo actual a la variable reco.
		}
	for(int x=1;x<columna;x++){ //Inicia otro ciclo for que se repetirá columna-1 veces, con la variable x inicializada en 1.
		reco=reco->sig;// En cada iteración del ciclo, se mueve a través del cubo al siguiente nodo a la derecha, asignando el puntero sig del nodo actual a la variable reco.
		}
	return reco->info;// Una vez que se llega al nodo deseado, la función devuelve el valor de info del nodo actual, que es el valor almacenado en la posición 
}
void imprimir() {
    struct nodo *reco = raiz1; //Declara e inicializa una variable de tipo struct nodo llamada reco que apunta a la misma dirección de memoria que la variable raiz1

    while (reco != NULL) { //Inicia un ciclo while que se repetirá mientras el puntero reco no sea NULL.
        struct nodo *temp = reco; //Declara e inicializa una variable de tipo struct nodo llamada temp que apunta a la misma dirección de memoria que la variable reco.
        while (temp != NULL) { //Inicia otro ciclo while que se repetirá mientras el puntero temp no sea NULL.
            printf("%i ", temp->info);//En cada iteración del ciclo, se imprime el valor de info del nodo actual.
            temp = temp->sig;//En cada iteración del ciclo, se mueve a través del cubo al siguiente nodo a la derecha, asignando el puntero sig del nodo actual a la variable temp.
        }
        reco = reco->arriba;//Al final del ciclo interno, se mueve a través del cubo al nodo que está encima, asignando el puntero arriba del nodo actual a la variable reco.
        printf("\n"); // Imprime una nueva línea después de imprimir todos los nodos de la fila actual.
    }
}
void crearcubo(){
		struct nodo *nuevo,*aux;
		// Se declara una variable de tipo struct nodo para representar un nuevo nodo, y un puntero auxiliar.
    // Este puntero se utilizará para apuntar al último nodo creado y así poder enlazarlo con el siguiente.
    // La idea general es ir recorriendo el cubo de manera ordenada, y para ello se necesitan tres bucles for anidados.
    // El primer bucle recorre las caras del cubo, el segundo las filas y el tercero las columnas.
	for(int x=1;x<6;x++){
		for(int y=1;y<5;y++){
			for(int z=1;z<5;z++){
				// Se verifica si el cubo está vacío, es decir, si no hay nodos aún.
				if (raiz1 == NULL){
					 // Se crea un nuevo nodo para la raíz del cubo.
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
			    // Si el cubo está vacío, se agrega el primer nodo. Este nodo se ubica en la primera posición
                    // del cubo (esquina inferior izquierda) y se le asigna el valor 5.
                    // Además, se inicializan los punteros raiz1, raiz2, raiz3 y aux para poder continuar la creación del cubo.
                    // El puntero aux se inicializa con raiz3 porque aún no hay columnas creadas.
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
			    // Cuando se han agregado todas las columnas de una fila, se agrega un nuevo nodo arriba del último nodo creado,
            // que representa la suma de los valores de la fila y se inicializa el puntero aux con el nuevo nodo.

				nuevo = (struct nodo*)malloc(sizeof(struct nodo));
				nuevo->info=x+y;
				nuevo->arriba=NULL;
				raiz3->arriba=nuevo;
			    raiz3=raiz3->arriba;
				aux=raiz3;
				// Si la fila es la última, se agregan cuatro nodos más para cerrar la cara del cubo.
				if(y==4){
				    for(int w=1;w<5;w++){
				        nuevo = (struct nodo*)malloc(sizeof(struct nodo));
				nuevo->info=x+y+w;
				nuevo->sig=NULL;
			    aux->sig=nuevo;
			    aux=aux->sig;
				    }
				    
				}// Cuando se han agregado todas las filas de una cara, se agrega un nuevo nodo adelante del último nodo creado,
        // que representa el número de la cara. Además, se inicializan los punteros raiz2, raiz3 y aux con el nuevo nodo.
				
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
    for(int x=1;x<6;x++){ //Dibujar cinco columnas de círculos en cada fila. La variable
        // Para dibujar cinco columnas de círculos en cada fila
        for(int y=1; y<6; y++){ //Dibujar en cada columna de la fila actual.
            int xPos = 200 + (100 * x) + (35 * n); // calcula la posición horizontal del círculo actual en la fila utilizando la variable x y el argumento n. 
            int yPos = 200 + (100 * y) - (35 * n);// calcula la posición vertical del círculo actual en la columna utilizando la variable y y el argumento n. 
            // Cada círculo será un cuadrado
            bar(xPos, yPos, xPos + 20, yPos + 20); //Esta línea dibuja un cuadrado de tamaño 20 x 20 en las coordenadas xPos y yPos
            gcvt(sacarDato(y, x, n), 6, resultado); //convierte un número decimal obtenido de la función sacarDato y lo almacena en resultado
            outtextxy(xPos - 10, yPos - 10, resultado); //muestra el valor de resultado en la posición (xPos - 10, yPos - 10) utilizando la función outtextxy.
        }
    }
}

