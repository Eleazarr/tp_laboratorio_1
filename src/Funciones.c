/*
 * Funciones.c
 *
 *  Created on: 15 abr. 2022
 *      Author: eleaz
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "Funciones.h"
/**
 * @fn void MenuPrincipal()
 * @brief 	Es el menu con un switch que llama a sus correspondientes funciones. Es el cuerpo principal de mi tp :(
 *
 */
void MenuPrincipal()
{
	int opcion;
	char seguir;
	seguir = 's';
	int kilometrosTotalesViaje;
	float precioVueloAerolineas;
	float precioVueloLatam;
	float precioDebitoAerolineas;
	float precioCreditoAerolineas;
	float precioDebitoLatam;
	float precioCreditoLatam;
	float precioBitcoinAerolineas;
	float precioBitcoinLatam;
	float precioUnitarioAerolineas;
	float precioUnitarioLatam;
	float diferenciaEntreVuelos;
	char kmMenu[10]="x";
	char precioMenuAerolineas[10]="y";
	char precioMenuLatam[10]="z";

	kilometrosTotalesViaje = 0;
	precioVueloAerolineas = 0;
	precioVueloLatam  = 0;


	do
	{
		printf("Bienvenidos al programa. Elija entre las opciones ja.\n");
		printf("1. Ingresar Kilometros: (km = %s) \n",kmMenu);
		printf("2. Ingresar Precio de Vuelos:(Aerolineas=%s, Latam=%s)\n  a)Precio vuelo Aerolineas:\n "
				" b)Precio vuelo Latam:\n",precioMenuAerolineas,precioMenuLatam);
		printf("3. Calcular todos los costos:\n  a) Tarjeta de debito(descuento 10 por ciento)\n  "
				"b) Tarjeta de credito (interes 25 por ciento)\n  c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n  d) Mostrar precio por km (precio unitario)\n  e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");
		printf("4. Informar Resultados\n  Latam:\n  a) Precio con tarjeta de debito: r\n  "
				"b) Precio con tarjeta de credito: r\n  c) Precio pagando con bitcoin : r\n  d) Precio unitario: "
				"r\n  Aerolíneas:\n  a) Precio con tarjeta de débito: r\n  b) Precio con tarjeta de crédito: r\n  "
				"c) Precio pagando con bitcoin : r\n  d) Precio unitario: r\n  La diferencia de precio es : r\n");
		printf("5. Carga forzada de datos\n");
		printf("6. Salir.\n\n OPCION? :");
		scanf("%d",&opcion);

		switch(opcion)
		{
			case 1:
				kilometrosTotalesViaje = IngresarEnteroPositivo("Ingrese los kilometros totales de su viaje por favor.\n");
				MensajeExitoso("KILOMETROS CARGADOS CON EXITO :D");
				sprintf(kmMenu, "%d", kilometrosTotalesViaje);
				break;
			case 2:
				precioVueloAerolineas = IngresarEnteroPositivo("Ingresar precio de vuelo para Aerolineas: ");
				precioVueloLatam = IngresarEnteroPositivo("Ingresar precio de vuelo para Latam: ");
				sprintf(precioMenuAerolineas,"%.2f",precioVueloAerolineas);
				sprintf(precioMenuLatam,"%.2f",precioVueloLatam);
				MensajeExitoso("PRECIOS CARGADOS CON EXITO :D");
				break;
			case 3:
				ComprobarNumero(kilometrosTotalesViaje,precioVueloAerolineas,precioVueloLatam,"perfecto ya mismo ejecuto su opcion\n","No se pueden hacer calculos sin kilometros y/o precios de los viajes!\nAhora va a tener que cargar ambos datos de nuevo para que funcione!\n");
				precioDebitoAerolineas = CalcularPorcentaje(precioVueloAerolineas,0.9);
				precioCreditoAerolineas = CalcularPorcentaje(precioVueloAerolineas,1.25);
				precioDebitoLatam = CalcularPorcentaje(precioVueloLatam,0.9);
				precioCreditoLatam = CalcularPorcentaje(precioVueloLatam,1.25);
				precioBitcoinAerolineas = BitcoinAPesos(precioVueloAerolineas);
				precioBitcoinLatam = BitcoinAPesos(precioVueloLatam);
				precioUnitarioAerolineas = DividirNumeros(kilometrosTotalesViaje,precioVueloAerolineas);
				precioUnitarioLatam = DividirNumeros(kilometrosTotalesViaje,precioVueloLatam);
				diferenciaEntreVuelos = RestarNumeros(precioVueloLatam,precioVueloAerolineas);
				MensajeExitoso("PRECIOS CALCULADOS CON EXITO :D");
				break;
			case 4:
				ComprobarNumero(kilometrosTotalesViaje,precioVueloAerolineas,precioVueloLatam,"perfecto ya mismo ejecuto su opcion\n","No se pueden hacer calculos sin kilometros y/o precios de los viajes!\nAhora va a tener que cargar ambos datos de nuevo para que funcione!\n");
				ImprimirVuelo(kilometrosTotalesViaje,precioVueloLatam,precioDebitoLatam,precioCreditoLatam,precioBitcoinLatam,precioUnitarioLatam,precioVueloAerolineas,precioDebitoAerolineas,precioCreditoAerolineas,precioBitcoinAerolineas,precioUnitarioAerolineas,diferenciaEntreVuelos);
				MensajeExitoso("IMPRESION EXITOSA :D");
				break;
			case 5:
				kilometrosTotalesViaje = 7090;
				precioVueloAerolineas = 162965;
				precioVueloLatam = 159339;
				precioDebitoAerolineas = CalcularPorcentaje(precioVueloAerolineas,0.9);
				precioCreditoAerolineas = CalcularPorcentaje(precioVueloAerolineas,1.25);
				precioDebitoLatam = CalcularPorcentaje(precioVueloLatam,0.9);
				precioCreditoLatam = CalcularPorcentaje(precioVueloLatam,1.25);
				precioBitcoinAerolineas = BitcoinAPesos(precioVueloAerolineas);
				precioBitcoinLatam = BitcoinAPesos(precioVueloLatam);
				precioUnitarioAerolineas = DividirNumeros(kilometrosTotalesViaje,precioVueloAerolineas);
				precioUnitarioLatam = DividirNumeros(kilometrosTotalesViaje,precioVueloLatam);
				diferenciaEntreVuelos = RestarNumeros(precioVueloLatam,precioVueloAerolineas);
				ImprimirVuelo(kilometrosTotalesViaje,precioVueloLatam,precioDebitoLatam,precioCreditoLatam,precioBitcoinLatam,precioUnitarioLatam,precioVueloAerolineas,precioDebitoAerolineas,precioCreditoAerolineas,precioBitcoinAerolineas,precioUnitarioAerolineas,diferenciaEntreVuelos);
				MensajeExitoso("CARGA FORZOSA EXITOSA :D");
				break;
			case 6:
				seguir = 'n';
				MensajeExitoso("Gracias por aprobarme!!!");
				break;
			default:
				MensajeExitoso("Opcion incorrecta elija bien del 1 al 6! >:( \n");
				break;
		}

	}while(seguir == 's');

}
/**
 * @fn int IngresarEnteroPositivo(char[])
 * @brief Pide enteros y verifica que sean mayores a 0, si no insiste hasta que pongan un numero valido
 *
 * @param condicionDeIngreso Mensaje dado por el usuario para que sepan a que variable le ingresan el entero
 * @return El numero ingresado por el usuario
 */
int IngresarEnteroPositivo(char condicionDeIngreso[])
{
	int numero;
	printf(condicionDeIngreso);
	scanf("%d",&numero);
	while(numero<1)
		{
			printf("Por favor ingrese numeros validos mayores a 0!!!");
			scanf("%d",&numero);
		}

	return numero;

}
/**
 * @fn float CalcularPorcentaje(float, float)
 * @brief Calcula un porcentaje dado cierto aumento o descuento expresado tomando el 1 como el precio base. Numeros menores representan descuento, mayores a 1 aumento.
 *
 * @param numero Valor al que se le hará el porcentaje con aumento o descuento
 * @param porcentaje Valor del aumento o descuento
 * @return numero aumentado un determinado porcentaje
 */
float CalcularPorcentaje(float numero, float porcentaje)
{
	float numeroFinal;

	numeroFinal = numero * porcentaje;

	return numeroFinal;
}
/**
 * @fn float BitcoinAPesos(float)
 * @brief Convierte determinada cantidad de pesos argentinos a bitcoins tomando un cambio arbitrario
 *
 * @param pesosArgentinos Cantidad de pesos argentinos que el usuario desea transformar a btc
 * @return equivalente en BTC de los ARS ingresados
 */
float BitcoinAPesos(float pesosArgentinos)
{
	float resultado;
	resultado =pesosArgentinos / BTCENARS;

	return resultado;
}
/**
 * @fn float DividirNumeros(int, int)
 * @brief Una simple division pero casteada a flotante para comodidad del resto del codigo
 *
 * @param divisor  el divisor
 * @param dividendo el dividendo
 * @return el resultado de la division ja
 */
float DividirNumeros(int divisor, int dividendo)
{
	float resultado;

	resultado = (float)dividendo / divisor;

	return resultado;
}
/**
 * @fn float RestarNumeros(float, float)
 * @brief Resta 2 numeros, saca su diferencia
 *
 * @param numero1 primer numero elegido por usuario
 * @param numero2 segundo numero elegido por usuario
 * @return la diferencia entre esos 2 numeros
 */
float RestarNumeros(float numero1, float numero2)
{
	float resultado;

	resultado = numero1 - numero2;

	return resultado;
}
/**
 * @fn void ImprimirVuelo(int, float, float, float, float, float, float, float, float, float, float, float)
 * @brief  Funcion que de un saque te imprime todos los datos que se calcularon anteriormente
 *
 * @param kilometros   kilometros que viaja el usuario
 * @param precioLatam  precio del viaje de latam
 * @param precio1       precio  latam pagando con debito
 * @param precio2		precio latam pagando con credito
 * @param precio3		precio latam pagando con btc
 * @param precio4		precio por km de latam
 * @param precioAerolineas  precio del viaje de aerolineas
 * @param precio5		precio aerolineas pagando con debito
 * @param precio6		precio aerolineas pagando con credito
 * @param precio7		precio aerolineas pagando con btc
 * @param precio8		precio por km de aerolineas
 * @param precio9		diferencia de precio entre aerolineas y latam
 */
void ImprimirVuelo(int kilometros,float precioLatam,float precio1,float precio2,float precio3,float precio4,float precioAerolineas,float precio5,float precio6,float precio7,float precio8,float precio9)
{
	printf("Kilometros totales: %d\n\n"
			"Precio Latam: $%.2f\n"
			"a) Precio con tarjeta de débito: $%.2f\n"
			"b) Precio con tarjeta de crédito: $%.2f\n"
			"c) Precio pagando con bitcoin : %.6f BTC\n"
			"d) Precio unitario: $%.2f\n\n"
			"Precio Aerolíneas: $%.2f\n"
			"a) Precio con tarjeta de débito: $%.2f\n"
			"b) Precio con tarjeta de crédito: $%.2f\n"
			"c) Precio pagando con bitcoin : %.6f BTC\n"
			"d) Precio unitario: $ %.2f \n\n	"
			"La diferencia de precio es : %.2f\n",kilometros,precioLatam,precio1,precio2,precio3,precio4,precioAerolineas,precio5,precio6,precio7,precio8,precio9);

}

/**
 * @fn void MensajeExitoso(char[])
 * @brief Una funcion que uso para resaltar los mensajes que salen en la consola y se distingan un poco mas entre tanto texto
 *
 * @param mensajito  Depende la funcion que la use recibe un texto que informa lo que precise.
 */
void MensajeExitoso(char mensajito[])
{
	printf(" \n\n ------------------------------- \n\n %s\n ------------------------------- \n",mensajito);
}
/**
 * @fn void ComprobarNumero(float, float, float, char[], char[])
 * @brief  Comprueba que se hayan ingresado los datos de km y ambos precios para que se pueda luego calcular los datos y/o mostrarlos en pantalla, impide que muestre basura luego
 *
 * @param kilometros  son los km que viaja el usuario
 * @param precioLatam  precio del vuelo de latam
 * @param precioAerolineas precio del vuelo de aerolineas
 * @param mensajeExito  mensaje para saber que cargo bien los datos y puede proseguir  al siguiente paso en orden
 * @param mensajeError   con esto se da cuenta de que le faltaron cargar datos y tiene que volver al paso 1
 */
void ComprobarNumero(float kilometros, float precioLatam, float precioAerolineas,char mensajeExito[],char mensajeError[])
{
	if(kilometros<1 || precioAerolineas<1 || precioLatam<1)
	{
		MensajeExitoso(mensajeError);//"No se pueden hacer calculos sin kilometros y/o precios de los viajes!\n"
		MenuPrincipal();
	}
	else
	{
		printf(mensajeExito);//"perfecto ya mismo ejecuto su opcion\n"
	}

}

