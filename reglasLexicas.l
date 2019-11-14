%{

//Importación de librerías
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Tokens.h"
#include "mainWindow.h"

%}

%option noyywrap
%option yylineno

ignoraComentarioMultiple \/\*[^*]*\*+(?:[^\/*][^*]*\*+)*\/
ignoraComentarioSimple \/\/(.*)
ignora [[:blank:]]|\t|\r|\n
identificador [_[:alpha:]][_[:alpha:]\d]*
entero (0[xX][[:xdigit:]]+)|(0[[:digit:]]+)|([[:digit:]]+)[lL]?
flotante [[:digit:]]+.[[:digit:]]+
caracter '([^'\\\n]|\\\\|\\n|\\t|\\r|\\\?)'
cadena \"[^"\n]*\"
tipo_dato_entero int
tipo_dato_caracter char
tipo_dato_flotante float
tipo_dato_doble double
conversion_tipo \({tipo_dato}\)

%%
{ignoraComentarioMultiple} {;}
{ignoraComentarioSimple}   {;}
{ignora}*                  {;}
{tipo_dato_entero}        {return(ID_PALABRA_CLAVE_TIPO_DATO_ENTERO);}
{tipo_dato_caracter}      {return(ID_PALABRA_CLAVE_TIPO_DATO_CARACTER);}
{tipo_dato_flotante}      {return(ID_PALABRA_CLAVE_TIPO_DATO_FLOTANTE);}
{tipo_dato_doble}         {return(ID_PALABRA_CLAVE_TIPO_DATO_DOBLE);}
"#define" 				  {return(ID_INSTRUCCION_PREPROCESADOR_DEFINE);}
"#include" 				  {return(ID_INSTRUCCION_PREPROCESADOR_INCLUDE);}
"#undef" 				  {return(ID_INSTRUCCION_PREPROCESADOR_UNDEF);}
"#ifdef" 				  {return(ID_INSTRUCCION_PREPROCESADOR_IFDEF);}
"#ifndef" 				  {return(ID_INSTRUCCION_PREPROCESADOR_IFNDEF);}
"#if" 				      {return(ID_INSTRUCCION_PREPROCESADOR_IF);}
"#else" 				  {return(ID_INSTRUCCION_PREPROCESADOR_ELSE);}
"#elif" 				  {return(ID_INSTRUCCION_PREPROCESADOR_ELIF);}
"#endif" 				  {return(ID_INSTRUCCION_PREPROCESADOR_ENDIF);}
"#error" 				  {return(ID_INSTRUCCION_PREPROCESADOR_ERROR);}
"#pragma" 				  {return(ID_INSTRUCCION_PREPROCESADOR_PRAGMA);}
"auto"		              {return(ID_PALABRA_CLAVE_VARIABLE_AUTOMATICA);}
"break"		              {return(ID_PALABRA_CLAVE_INSTRUCCION_INTERRUPCION);}
"case"		              {return(ID_PALABRA_CLAVE_ETIQUETA_CASO_POSIBLE);}
"continue"                {return(ID_PALABRA_CLAVE_INSTRUCCION_CONTINUAR);}
"default"		          {return(ID_PALABRA_CLAVE_ETIQUETA_DEMAS_CASOS);}
"do"		              {return(ID_PALABRA_CLAVE_INSTRUCCION_CON_PRUEBA_FINAL);}
"else"		              {return(ID_PALABRA_CLAVE_SUBINSTRUCCION_EN_CASO_CONTRARIO);}
"extern"                  {return(ID_PALABRA_CLAVE_VARIABLE_EXTERNA);}
"for"		              {return(ID_PALABRA_CLAVE_INSTRUCCION_CICLO);}
"gets"                    {return(ID_FUNCIONES_ENTRADA_SALIDA_ENTRADA_LINEA);}
"goto"		              {return(ID_PALABRA_CLAVE_INSTRUCCION_SALTA_INCONDICIONAL);}
"if"		              {return(ID_PALABRA_CLAVE_INSTRUCCION_CONDICIONAL);}
"long"		              {return(ID_PALABRA_CLAVE_TIPO_ENTERO_LONG_GRAND);}
"printf"                  {return(ID_FUNCIONES_ENTRADA_SALIDA_SALIDA_FORMATEADA);}
"putchar"                 {return(ID_FUNCIONES_ENTRADA_SALIDA_ESTANDAR_CARACTER);}
"puts"                    {return(ID_FUNCIONES_ENTRADA_SALIDA_SALIDA_LINEA);}
"register"                {return(ID_PALABRA_CLAVE_VARIABLE_REGISTRO);}
"return"		          {return(ID_PALABRA_CLAVE_INSTRUCCION_RETURNAR);}
"scanf"                   {return(ID_FUNCIONES_ENTRADA_SALIDA_ENTRADA_FORMATEADA);}
"short"		              {return(ID_PALABRA_CLAVE_TIPO_ENTERO_LONG_PEQ);}
"sizeof"	              {return(ID_PALABRA_CLAVE_FUNCION_TAMANO_OBJETO);}
"static"                  {return(ID_PALABRA_CLAVE_VARIABLE_ESTATICA);}
"struct"	              {return(ID_PALABRA_CLAVE_ESTRUCTURA);}
"switch"	              {return(ID_PALABRA_CLAVE_INSTRUCCION_SALTO_CONDICIONAL);}
"typedef"	              {return(ID_PALABRA_CLAVE_DEFINICION_TIPO);}
"union"		              {return(ID_PALABRA_CLAVE_UNION);}
"unsigned"		          {return(ID_PALABRA_CLAVE_TIPO_ENTERO_SIN_SIGN);}
"void"                    {return(ID_PALABRA_CLAVE_ETIQUETA_AUSENCIA_TIPO);}
"while"		              {return(ID_PALABRA_CLAVE_INSTRUCCION_CICLO_PRUEBA_INICIO);}
getch|getchar             {return(ID_FUNCIONES_ENTRADA_SALIDA_ENTRADA_CARACTER_1_2);}
{flotante}	              {return(ID_CONSTANTE_FLOTANTE);}
{entero}	              {return(ID_CONSTANTE_ENTERO);}
{cadena}	              {return(ID_CONSTANTE_CADENA);}
{identificador}	          {return(ID_IDENTIFICADOR);}
{caracter}	              {return(ID_CONSTANTE_CARACTER);}
">>="		              {return(ID_OPERADOR_ASIGN_CORR_DER);}
"<<="		              {return(ID_OPERADOR_ASIGN_CORR_IZQ);}
"<="				      {return(ID_OPERADOR_REL_MENOROIGUAL_QUE);}
">="				      {return(ID_OPERADOR_REL_MAYOROIGUAL_QUE);}
"=="		              {return(ID_OPERADOR_REL_IGUAL_QUE);}
"!="		              {return(ID_OPERADOR_REL_DIFERENTE_DE);}
"||"		              {return(ID_OPERADOR_LOG_FUNCION_O);}
"&&"		              {return(ID_OPERADOR_LOG_FUNCION_Y);}
"|="		              {return(ID_OPERADOR_ASIGN_VENT_O_LOG);}
"&="		              {return(ID_OPERADOR_ASIGN_VENT_Y_LOG);}
"+="		              {return(ID_OPERADOR_ASIGN_INC_ARIT);}
"-="		              {return(ID_OPERADOR_ASIGN_DEC_ARIT);}
"*="		              {return(ID_OPERADOR_ASIGN_INC_GEO);}
"/="		              {return(ID_OPERADOR_ASIGN_DEC_GEO);}
"%="		              {return(ID_OPERADOR_ASIGN_MODULO);}
"^="		              {return(ID_OPERADOR_ASIGN_VENT_O_EX);}
"++"		              {return(ID_OPERADOR_TIPO_LENG_ENSAMB_INC_UNIT);}
"--"		              {return(ID_OPERADOR_TIPO_LENG_ENSAMB_DEC_UNIT);}
">>"		              {return(ID_OPERADOR_TIPO_LENG_ENSAMB_CORR_IZQ);}
"<<"		              {return(ID_OPERADOR_TIPO_LENG_ENSAMB_CORR_DER);}
"->"		              {return(ID_OPERADOR_EXP_PRIM_CAMPO_MODO_INDIRECTO);}
"?"  		              {return(ID_OPERADOR_FUNC_ESP_EXP_CONDICIONAL);}
"+"				          {return(ID_OPERADOR_ARIT_SUMA);}
"-"				          {return(ID_OPERADOR_ARIT_NEG_RESTA);}
"*"				          {return(ID_OPERADOR_ARIT_MULTIPLICACION_TIPO_LENG_ENSAMB_INDIREC_EXP_PRIM_APUNTADOR);}
"/"				          {return(ID_OPERADOR_ARIT_DIVISION);}
"%"				          {return(ID_OPERADOR_ARIT_RESIDUO);}
"<"				          {return(ID_OPERADOR_REL_MENOR_QUE);}
">"				          {return(ID_OPERADOR_REL_MAYOR_QUE);}
"!"   		              {return(ID_OPERADOR_LOG_NEGACION);}
"~"		                  {return(ID_OPERADOR_LOG_BIT_COMPLEMENTO_1);}
"|"		                  {return(ID_OPERADOR_LOG_BIT_FUNCION_O);}
"&"		                  {return(ID_OPERADOR_LOG_BIT_FUNCION_Y_TIPO_LENG_ENSAMB_APUNTADOR);}
"^"		                  {return(ID_OPERADOR_LOG_BIT_FUNCION_O_EX);}
"="		                  {return(ID_OPERADOR_ASIGN_SIMPLE);}
"{"				          {return(ID_APERTURA_BLOQUE);}
"}"				          {return(ID_CIERRE_BLOQUE);}
"("		                  {return(ID_OPERADOR_EXP_PRIM_PARENTESIS_APERTURA);}
")"		                  {return(ID_OPERADOR_EXP_PRIM_PARENTESIS_CIERRE);}
"["		                  {return(ID_OPERADOR_EXP_PRIM_CORCHETE_APERTURA);}
"]"		                  {return(ID_OPERADOR_EXP_PRIM_CORCHETE_CIERRE);}
"."		                  {return(ID_OPERADOR_EXP_PRIM_CAMPO_MODO_DIRECTO);}
":"		                  {return(ID_OPERADOR_FUNC_ESP_EXP_INTERMEDIA);}
";"				          {return(ID_TERMINADOR_INSTRUCCION);}
","				          {return(ID_SEPARADOR_COMA);}

.				          {return(ID_ERROR_CODE);}

%%

//Clase principal main()
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
    const int width = 950;
    const int height = 600;
    const int xScreen = (GetSystemMetrics(SM_CXSCREEN)-width)/2;
    const int yScreen = (GetSystemMetrics(SM_CYSCREEN)-height)/2;
    WNDCLASSW wc = { 0 };
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"miClaseWindow";
    wc.lpfnWndProc = WindowProcedure;
    if(!RegisterClassW(&wc))
    {
        return -1;
    }
    hMainWindow = CreateWindowW(L"miClaseWindow", L"Analizador Lexico para el lenguaje C", WS_VISIBLE | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, xScreen, yScreen, width, height, NULL, NULL, NULL, NULL);
    MSG msg = { 0 };
    while(GetMessage(&msg, NULL, NULL, NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
