Algoritmo telemetria
	
	//Declaramos variables
	Definir t Como Entero; //t numero de segundos desde el inicio en que se toma la lectura
	Definir i, suma_i, media Como Real; //i indica la lectura telemetrica en metros realizada en el instante t
	Definir n Como Entero; //utilizamos n como indice
	
	Escribir "Indica los segundos";
	Leer t;
	Escribir "Indica los metros";
	Leer i;
	
	n = 1;
	suma_i = i;
	
	Mientras t != -1 Hacer
		Escribir "Indica los segundos";
		Leer t;
		si t != -1 Entonces
			Escribir "Indica los metros";
			Leer i;
			suma_i = suma_i + i;
			n = n + 1;
		FinSi
	Fin Mientras
	media = suma_i / n;
	Escribir "Fin de lecturas. La media es " media;
	
FinAlgoritmo
