#ifndef TOKENS_H_INCLUDED
#define TOKENS_H_INCLUDED

#define ID_ERROR_CODE 500
#define ID_TERMINADOR_INSTRUCCION 300
#define ID_APERTURA_BLOQUE 301
#define ID_CIERRE_BLOQUE 302
#define ID_CONSTANTE_ENTERO 303
#define ID_CONSTANTE_FLOTANTE 304
#define ID_CONSTANTE_CARACTER 305
#define ID_CONSTANTE_CADENA 306
#define ID_IDENTIFICADOR 307
#define ID_OPERADOR_ARIT_SUMA 308
#define ID_OPERADOR_ARIT_NEG_RESTA 309
#define ID_OPERADOR_ARIT_MULTIPLICACION_TIPO_LENG_ENSAMB_INDIREC_EXP_PRIM_APUNTADOR 310
#define ID_OPERADOR_ARIT_DIVISION 311
#define ID_OPERADOR_ARIT_RESIDUO 312
#define ID_OPERADOR_REL_MENOR_QUE 313
#define ID_OPERADOR_REL_MAYOR_QUE 314
#define ID_OPERADOR_REL_MENOROIGUAL_QUE 315
#define ID_OPERADOR_REL_MAYOROIGUAL_QUE 316
#define ID_OPERADOR_REL_IGUAL_QUE 317
#define ID_OPERADOR_REL_DIFERENTE_DE 318
#define ID_OPERADOR_LOG_NEGACION 319
#define ID_OPERADOR_LOG_FUNCION_O 320
#define ID_OPERADOR_LOG_FUNCION_Y 321
#define ID_OPERADOR_LOG_BIT_COMPLEMENTO_1 322
#define ID_OPERADOR_LOG_BIT_FUNCION_O 323
#define ID_OPERADOR_LOG_BIT_FUNCION_Y_TIPO_LENG_ENSAMB_APUNTADOR 324
#define ID_OPERADOR_LOG_BIT_FUNCION_O_EX 325
#define ID_OPERADOR_ASIGN_SIMPLE 326
#define ID_OPERADOR_ASIGN_INC_ARIT 327
#define ID_OPERADOR_ASIGN_DEC_ARIT 328
#define ID_OPERADOR_ASIGN_INC_GEO 329
#define ID_OPERADOR_ASIGN_DEC_GEO 330
#define ID_OPERADOR_ASIGN_MODULO 331
#define ID_OPERADOR_ASIGN_CORR_DER 332
#define ID_OPERADOR_ASIGN_CORR_IZQ 333
#define ID_OPERADOR_ASIGN_VENT_O_LOG 334
#define ID_OPERADOR_ASIGN_VENT_Y_LOG 335
#define ID_OPERADOR_ASIGN_VENT_O_EX 336
#define ID_OPERADOR_TIPO_LENG_ENSAMB_CORR_IZQ 337
#define ID_OPERADOR_TIPO_LENG_ENSAMB_CORR_DER 338
#define ID_OPERADOR_TIPO_LENG_ENSAMB_INC_UNIT 339
#define ID_OPERADOR_TIPO_LENG_ENSAMB_DEC_UNIT 340
#define ID_OPERADOR_EXP_PRIM_PARENTESIS_APERTURA 341
#define ID_OPERADOR_EXP_PRIM_PARENTESIS_CIERRE 342
#define ID_OPERADOR_EXP_PRIM_CORCHETE_APERTURA 343
#define ID_OPERADOR_EXP_PRIM_CORCHETE_CIERRE 344
#define ID_OPERADOR_EXP_PRIM_CAMPO_MODO_INDIRECTO 345
#define ID_OPERADOR_EXP_PRIM_CAMPO_MODO_DIRECTO 346
#define ID_OPERADOR_FUNC_ESP_EXP_CONDICIONAL 347
#define ID_OPERADOR_FUNC_ESP_EXP_INTERMEDIA 348
#define ID_PALABRA_CLAVE_TIPO_DATO_ENTERO 349
#define ID_PALABRA_CLAVE_ESTRUCTURA 350
#define ID_PALABRA_CLAVE_UNION 351
#define ID_PALABRA_CLAVE_TIPO_ENTERO_LONG_GRAND 352
#define ID_PALABRA_CLAVE_TIPO_ENTERO_LONG_PEQ 353
#define ID_PALABRA_CLAVE_TIPO_ENTERO_SIN_SIGN 354
#define ID_PALABRA_CLAVE_VARIABLE_AUTOMATICA 355
#define ID_PALABRA_CLAVE_VARIABLE_EXTERNA 356
#define ID_PALABRA_CLAVE_VARIABLE_REGISTRO 357
#define ID_PALABRA_CLAVE_VARIABLE_ESTATICA 358
#define ID_PALABRA_CLAVE_DEFINICION_TIPO 359
#define ID_PALABRA_CLAVE_INSTRUCCION_SALTA_INCONDICIONAL 360
#define ID_PALABRA_CLAVE_INSTRUCCION_RETURNAR 361
#define ID_PALABRA_CLAVE_FUNCION_TAMANO_OBJETO 362
#define ID_PALABRA_CLAVE_INSTRUCCION_INTERRUPCION 363
#define ID_PALABRA_CLAVE_INSTRUCCION_CONTINUAR 364
#define ID_PALABRA_CLAVE_INSTRUCCION_CONDICIONAL 365
#define ID_PALABRA_CLAVE_SUBINSTRUCCION_EN_CASO_CONTRARIO 366
#define ID_PALABRA_CLAVE_INSTRUCCION_CICLO 367
#define ID_PALABRA_CLAVE_INSTRUCCION_CON_PRUEBA_FINAL 368
#define ID_PALABRA_CLAVE_INSTRUCCION_CICLO_PRUEBA_INICIO 369
#define ID_PALABRA_CLAVE_INSTRUCCION_SALTO_CONDICIONAL 370
#define ID_PALABRA_CLAVE_ETIQUETA_CASO_POSIBLE 371
#define ID_PALABRA_CLAVE_ETIQUETA_DEMAS_CASOS 372
#define ID_PALABRA_CLAVE_ETIQUETA_AUSENCIA_TIPO 373
#define ID_FUNCIONES_ENTRADA_SALIDA_ENTRADA_CARACTER_1_2 374
#define ID_FUNCIONES_ENTRADA_SALIDA_ESTANDAR_CARACTER 375
#define ID_FUNCIONES_ENTRADA_SALIDA_ENTRADA_FORMATEADA 376
#define ID_FUNCIONES_ENTRADA_SALIDA_SALIDA_FORMATEADA 377
#define ID_FUNCIONES_ENTRADA_SALIDA_ENTRADA_LINEA 378
#define ID_FUNCIONES_ENTRADA_SALIDA_SALIDA_LINEA 379
#define ID_SEPARADOR_COMA 380
#define ID_INSTRUCCION_PREPROCESADOR_DEFINE 381
#define ID_INSTRUCCION_PREPROCESADOR_INCLUDE 382
#define ID_INSTRUCCION_PREPROCESADOR_UNDEF 383
#define ID_INSTRUCCION_PREPROCESADOR_IFDEF 384
#define ID_INSTRUCCION_PREPROCESADOR_IFNDEF 385
#define ID_INSTRUCCION_PREPROCESADOR_IF 386
#define ID_INSTRUCCION_PREPROCESADOR_ELSE 387
#define ID_INSTRUCCION_PREPROCESADOR_ELIF 388
#define ID_INSTRUCCION_PREPROCESADOR_ENDIF 389
#define ID_INSTRUCCION_PREPROCESADOR_ERROR 390
#define ID_INSTRUCCION_PREPROCESADOR_PRAGMA 391
#define ID_PALABRA_CLAVE_TIPO_DATO_CARACTER 392
#define ID_PALABRA_CLAVE_TIPO_DATO_FLOTANTE 393
#define ID_PALABRA_CLAVE_TIPO_DATO_DOBLE 394

char* obtenerNombreToken(int*);

char* obtenerNombreToken(int *token){
    switch(*token){
    case 300: return "Terminador de instruccion";
    case 301: return "Apertura de bloque";
    case 302: return "Cierre de bloque";
    case 303: return "Entero";
    case 304: return "Flotante";
    case 305: return "Caracter";
    case 306: return "Cadena";
    case 307: return "Identificador";
    case 308: return "Suma";
    case 309: return "Negativo/Resta";
    case 310: return "Multipliacion/Indireccion/Apuntador";
    case 311: return "Division";
    case 312: return "Residuo";
    case 313: return "Menor que";
    case 314: return "Mayor que";
    case 315: return "Menor o igual que";
    case 316: return "Mayor o igual que";
    case 317: return "Igual que";
    case 318: return "Diferente de";
    case 319: return "Negación Logica";
    case 320: return "O logico";
    case 321: return "Y logico";
    case 322: return "Complemento a 1";
    case 323: return "O logico nivel bit";
    case 324: return "Y logico nivel bit/Apuntador";
    case 325: return "O logico exclusivo";
    case 326: return "Asignacion simple";
    case 327: return "Incremento aritmetico";
    case 328: return "Decremento aritmetico";
    case 329: return "Incremento geometrico";
    case 330: return "Decremento geometrico";
    case 331: return "Modulo";
    case 332: return "Corrimiento a la derecha";
    case 333: return "Corrimiento a la izquierda";
    case 334: return "Ventana O logico";
    case 335: return "Ventana Y logico";
    case 336: return "Ventana O logico exclusivo";
    case 337: return "Corrimiento a la derecha";
    case 338: return "Corrimiento a la izquierda";
    case 339: return "Incremento unitario";
    case 340: return "Decremento unitario";
    case 341: return "Parentesis de apertura";
    case 342: return "Parentesis de cierre";
    case 343: return "Corchete de apertura";
    case 344: return "Corchete de cierre";
    case 345: return "Campo (modo indirecto)";
    case 346: return "Punto";
    case 347: return "Expresion condicional";
    case 348: return "Expresion intermedia";
    case 349: return "Tipo dato entero";
    case 350: return "Estructura";
    case 351: return "Union";
    case 352: return "Tipo entero de longitud grande";
    case 353: return "Tipo entero de longitud pequena";
    case 354: return "Tipo entero sin signo";
    case 355: return "Variable automatica";
    case 356: return "Variable externa";
    case 357: return "Variable registro";
    case 358: return "Variable estatica";
    case 359: return "Definicion de tipo de dato";
    case 360: return "Instruccion salta incondicional";
    case 361: return "Instruccion dato a retornar";
    case 362: return "Funcion tamano de objeto sizeof";
    case 363: return "Instruccion interrupcion break";
    case 364: return "Instruccion continuar";
    case 365: return "Instruccion condicional if";
    case 366: return "Subinstruccion caso contrario else";
    case 367: return "Instruccion ciclo for";
    case 368: return "Instruccion ciclo do";
    case 369: return "Instruccion ciclo while";
    case 370: return "Instruccion condicional switch";
    case 371: return "Instruccion caso posible para switch";
    case 372: return "Instruccion por defecto para switch";
    case 373: return "Ausencia de tipo de dato";
    case 374: return "Entrada estandar caracter por caracter";
    case 375: return "Salida estandar caracter por caracter";
    case 376: return "Entrada formateada scanf";
    case 377: return "Salida formateada printf";
    case 378: return "Entrada estandar línea por linea";
    case 379: return "Salida estandar línea por linea";
    case 380: return "Separador coma";
    case 381: return "Instruccion preprocesador #define";
    case 382: return "Instruccion preprocesador #include";
    case 383: return "Instruccion preprocesador #undef";
    case 384: return "Instruccion preprocesador #ifdef";
    case 385: return "Instruccion preprocesador #ifndef";
    case 386: return "Instruccion preprocesador #if";
    case 387: return "Instruccion preprocesador #else";
    case 388: return "Instruccion preprocesador #elif";
    case 389: return "Instruccion preprocesador #endif";
    case 390: return "Instruccion preprocesador #error";
    case 391: return "Instruccion preprocesador #pragma";
    case 392: return "Tipo dato caracter";
    case 393: return "Tipo dato punto flotante";
    case 394: return "Tipo dato doble precision";
    default: return "";
    }
}

#endif // TOKENS_H_INCLUDED
