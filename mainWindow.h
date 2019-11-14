#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <windows.h>

//Definición de constantes globales
#define BOTON_ABRIR_ARCHIVO 1
#define BOTON_GUARDAR_ARCHIVO 2
#define BOTON_LIMPIAR 3
#define BOTON_ANALIZAR 4
#define BOTON_GUARDAR_RESULTADO 5

//Definición de variables globales
HWND hMainWindow, hTextoIngresado, hResultado, hLogo;
HBITMAP hLogoImagen;

//Definición de funciones y procedimientos
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
void cargarImagenes();
void agregarControles(HWND);
void mostrarArchivo(char*);
void abrirArchivo(HWND);
void escribirArchivo(char*, HWND);
void guardarArchivo(HWND, HWND);
void realizarAnalisis();

void mostrarArchivo(char* path)
{
    FILE *archivo;
    archivo = fopen(path, "rb");
    fseek(archivo, 0, SEEK_END);
    int _size = ftell(archivo);
    rewind(archivo);
    char *data = (char*)malloc(_size+1);//En C++ es new char[_size+1];
    fread(data, _size, 1, archivo);
    data[_size] = '\0';
    SetWindowText(hTextoIngresado, data);
    SetWindowText(hResultado, "");
    fclose(archivo);
    free(data);
}

void abrirArchivo(HWND hWnd)
{
    OPENFILENAME ofn;
    char file_name[100];
    ZeroMemory(&ofn, sizeof(OPENFILENAME));
    ofn.lpstrTitle = "Abrir archivo para el analisis";
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = hWnd;
    ofn.lpstrFile = file_name;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = 100;
    ofn.lpstrFilter = "Archivos C (*.c;*.h)\0*.c;*.h\0Todos los archivos\0*.*\0";
    ofn.nFilterIndex = 1;
    GetOpenFileName(&ofn);
    if(strlen(ofn.lpstrFile)>0)
    {
        mostrarArchivo(ofn.lpstrFile);
    }
}

void escribirArchivo(char* path, HWND handlerTextBox)
{
    FILE *archivo;
    archivo = fopen(path, "w");
    int _size = GetWindowTextLength(handlerTextBox);
    char* data = (char*)malloc(_size+1);//En C++ es new char[_size+1];
    GetWindowText(handlerTextBox, data, _size+1);
    fwrite(data, _size+1, 1, archivo);
    fclose(archivo);
    free(data);
}

void guardarArchivo(HWND hWnd, HWND handlerTextBox)
{
    OPENFILENAME ofn;
    char file_name[100];
    ZeroMemory(&ofn, sizeof(OPENFILENAME));
    ofn.lpstrTitle = "Guardar archivo";
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = hWnd;
    ofn.lpstrFile = file_name;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = 100;
    ofn.lpstrFilter = "Archivo de texto\0*.txt\0";
    ofn.lpstrDefExt = ".txt";
    ofn.nFilterIndex = 1;
    GetSaveFileName(&ofn);
    if(strlen(ofn.lpstrFile)>0)
    {
        escribirArchivo(ofn.lpstrFile, handlerTextBox);
    }
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch(msg)
    {
    case WM_COMMAND:
        switch(wp)
        {
        case BOTON_ABRIR_ARCHIVO:
            abrirArchivo(hWnd);
            break;
        case BOTON_GUARDAR_ARCHIVO:
            if(GetWindowTextLength(hTextoIngresado)>0)
            {
                guardarArchivo(hWnd, hTextoIngresado);
            }
            else
            {
                MessageBox(hMainWindow, "No se puede guardar un archivo fuente sin datos.", "Error!", MB_OK | MB_ICONERROR);
            }
            break;
        case BOTON_LIMPIAR:
            if(GetWindowTextLength(hTextoIngresado)>0 || GetWindowTextLength(hResultado)>0)
            {
                SetWindowText(hTextoIngresado, "");
                SetWindowText(hResultado, "");
            }
            else
            {
                MessageBox(hMainWindow, "No existen datos para limpiar.", "Error!", MB_OK | MB_ICONERROR);
            }
            break;
        case BOTON_ANALIZAR:
            if(GetWindowTextLength(hTextoIngresado)>0)
            {
                realizarAnalisis();
            }
            else
            {
                MessageBox(hMainWindow, "No existen datos para analizarlos.", "Error!", MB_OK | MB_ICONERROR);
            }
            break;
        case BOTON_GUARDAR_RESULTADO:
            if(GetWindowTextLength(hResultado)>0)
            {
                guardarArchivo(hWnd, hResultado);
            }
            else
            {
                MessageBox(hMainWindow, "No se puede guardar un archivo de resultados sin datos.", "Error!", MB_OK | MB_ICONERROR);
            }
            break;
        }
        break;
    case WM_CREATE:
        cargarImagenes();
        agregarControles(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
    }
}

void cargarImagenes()
{
    hLogoImagen = (HBITMAP) LoadImageW(NULL, L"logo.bmp", IMAGE_BITMAP, 350, 200, LR_LOADFROMFILE);
}

void agregarControles(HWND hWnd)
{
    CreateWindowW(L"Button", L"Abrir", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 25, 240, 70, 20, hWnd, (HMENU) BOTON_ABRIR_ARCHIVO, NULL, NULL);
    CreateWindowW(L"Button", L"Guardar", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 120, 240, 70, 20, hWnd, (HMENU) BOTON_GUARDAR_ARCHIVO, NULL, NULL);
    CreateWindowW(L"Button", L"Limpiar", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 210, 240, 70, 20, hWnd, (HMENU) BOTON_LIMPIAR, NULL, NULL);
    CreateWindowW(L"Button", L"&Analizar", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 300, 240, 70, 20, hWnd, (HMENU) BOTON_ANALIZAR, NULL, NULL);
    hTextoIngresado = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | ES_MULTILINE | WS_BORDER | WS_VSCROLL | WS_HSCROLL, 25, 275, 350, 275, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Static", L"Resultado del analisis:", WS_VISIBLE | WS_CHILD, 425, 25, 200, 20, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"Guardar Resultado", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 795, 25, 130, 20, hWnd, (HMENU) BOTON_GUARDAR_RESULTADO, NULL, NULL);
    hResultado = CreateWindowW(L"Edit", L"", ES_LEFT | ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_BORDER | WS_VSCROLL | WS_HSCROLL | ES_READONLY, 425, 55, 500, 495, hWnd, NULL, NULL, NULL);
    hLogo = CreateWindowW(L"Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 25, 25, 350, 200, hWnd, NULL, NULL, NULL);
    SendMessageW(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hLogoImagen);
}

void realizarAnalisis()
{
    int token;
    int _size = GetWindowTextLength(hTextoIngresado);
    char* data = (char*)malloc(_size+1);//En C++ es new char[_size+1];
    GetWindowText(hTextoIngresado, data, _size+1);

    char resultados[90000] = "", numero[10] = "";

    yy_scan_string(data);

    while((token=yylex())>0)
    {
        if(token==500) //CÓDIGO DE ERROR
        {
            strcat(resultados, "LINEA NRO ");
            strcat(resultados, itoa(yylineno, numero, 10));
            strcat(resultados, ", ERROR LEXICO EN ");
            strcat(resultados, yytext);
        }
        else
        {
            strcat(resultados, "LEXEMA  ");
            strcat(resultados, yytext);
            strcat(resultados, "   TOKEN ");
            strcat(resultados, itoa(token, numero, 10));
            strcat(resultados, "  ");
            strcat(resultados, obtenerNombreToken(&token));

        }
        strcat(resultados, "\r\n");
    };
    SetWindowText(hResultado, resultados);
    MessageBox(hMainWindow, "Analisis lexico realizado correctamente.", "Info!", MB_OK | MB_ICONINFORMATION);
    yy_delete_buffer(YY_CURRENT_BUFFER);
    yylex_destroy();
}

#endif // MAINWINDOW_H_INCLUDED
