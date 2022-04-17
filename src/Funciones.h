/*
 * Funciones.h
 *
 *  Created on: 15 abr. 2022
 *      Author: eleaz
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#define BTCENARS 4606954.55
/**
 * @fn void MenuPrincipal()
 * @brief
 *
 */
void MenuPrincipal();
int IngresarEnteroPositivo(char condicionDeIngreso[]);
float CalcularPorcentaje(float numero, float porcentaje);
float BitcoinAPesos(float pesosArgentinos);
float DividirNumeros(int divisor, int dividendo);
float RestarNumeros(float numero1, float numero2);
void ImprimirVuelo(int kilometros,float precioLatam,float precio1,float precio2,float precio3,float precio4,float precioAerolineas,float precio5,float precio6,float precio7,float precio8,float precio9);
void MensajeExitoso(char mensajito[]);
void ComprobarNumero(float kilometros, float precioLatam, float precioAerolineas,char mensajeExito[],char mensajeError[]);



#endif /* FUNCIONES_H_ */
