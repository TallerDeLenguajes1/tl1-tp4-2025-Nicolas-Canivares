#include <stdio.h>   
#include <stdlib.h>

int idIncremental = 1000; //Variable global para el ID de la tarea

struct{
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
} typedef Tarea;

struct{
    Tarea Tarea; //Dato
    Nodo *Siguiente; //Puntero al siguiente nodo
} typedef Nodo;

void crearTarea(Tarea *tareas);

Nodo * CrearListaVacia();

Nodo * CrearNodo(Tarea nuevaTarea);



int main()
{
    srand(time(NULL)); // Inicializa la semilla para la función rand()
    Nodo *listaTareasPendientes;
    // Crear la lista vacía de tareas pendientes
    listaTareasPendientes = CrearListaVacia();

    int opcion, seguir = 1;
    Tarea nuevaTarea;
    
    

    //MENU
    do
    {

        printf("1. Crear tarea pendiente\n");
        printf("Ingrese la opcion deseada:\n");
        scanf("%d", &opcion);
        if (opcion == 1)
        {   
            while (seguir != 0)
            {
                crearTarea(&nuevaTarea);
                printf("Desea crear otra tarea? (1: Si, 0: No)\n");
                scanf("%d", &seguir);
                Nodo *NuevoNodo = CrearNodo(nuevaTarea);

            }
            
        }
        
    } while (opcion != 0);
    



    return 0;
}

void crearTarea(Tarea *tareas){
    tareas->TareaID = idIncremental;
    printf("Ingrese la descripcion de la tarea:\n");
    char *descripcion = (char *) malloc(100 * sizeof(char));
    gets(descripcion);
    fflush(stdin);
    int tamanioDescripcion = strlen(descripcion);
    tareas->Descripcion = (char *) malloc((tamanioDescripcion + 1) * sizeof(char));
    strcpy(tareas->Descripcion, descripcion);
    free(descripcion); // Liberar memoria de la variable temporal
    tareas->Duracion = rand() % 91 + 10; // Genera un número aleatorio entre 10 y 100
    idIncremental++;
    printf("Tarea creada!\n");
}

Nodo * CrearNodo(Tarea nuevaTarea)
{
    Nodo * nuevoNodo = (Nodo *) malloc (sizeof(Nodo));
    nuevoNodo->Tarea = nuevaTarea;
    nuevoNodo->Siguiente = NULL;
    return nuevoNodo;
}

Nodo * CrearListaVacia()
{
    return NULL;
}