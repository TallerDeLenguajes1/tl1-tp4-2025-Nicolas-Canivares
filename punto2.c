#include <stdio.h>   
#include <stdlib.h>
#include <string.h>
#include <time.h>

int idIncremental = 1000; //Variable global para el ID de la tarea

struct{
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
} typedef Tarea;

typedef struct Nodo{
    Tarea Tarea; //Dato
    struct Nodo *Siguiente; //Puntero al siguiente nodo
} Nodo;

void crearTarea(Tarea *tareas);

Nodo * CrearListaVacia();

Nodo * CrearNodo(Tarea nuevaTarea);

//Funcion para insertar un nodo al comienzo de la lista
void insertarNodo(Nodo **lista, Nodo *nuevoNodo);

void listarTareas(Nodo **listaTareas);

int main()
{
    srand(time(NULL)); // Inicializa la semilla para la función rand()
    Nodo *listaTareasPendientes;
    Nodo *listaTareasRealizadas;
    // Crear la lista vacía de tareas pendientes
    listaTareasPendientes = CrearListaVacia();
    listaTareasRealizadas = CrearListaVacia();
    int opcion, seguir = 1, idTarea;
    Tarea nuevaTarea;

    //MENU
    do
    {

        printf("1. Crear tarea pendiente\n");
        printf("2. Cambiar estado a realizada\n");
        printf("3. Listas todas las tareas");
        printf("0. Salir\n");
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
                insertarNodo(&listaTareasPendientes, NuevoNodo); // Insertar el nuevo nodo en la lista
            }
        }else if (opcion == 2)
        {
            printf("Tareas pendientes:\n");
            listarTareas(&listaTareasPendientes);
            printf("Ingrese el ID de la tarea a cambiar a realizada:\n");
            scanf("%d", &idTarea);
            Nodo *tareaEncontrada = buscarTarea(listaTareasPendientes,idTarea);
            insertarNodo(&listaTareasRealizadas, tareaEncontrada);
            printf("Tareas Realizadas:\n");
            listarTareas(&listaTareasRealizadas);
        }else if (opcion == 3)
        {
            printf("TAREAS PENDIENTES: \n");
            listarTareas(&listaTareasPendientes);
            printf("TAREAS REALIZADAS: \n");
            listarTareas(&listaTareasRealizadas);
        }
        
    } while (opcion != 0);
    
    return 0;
}

void crearTarea(Tarea *tareas){
    tareas->TareaID = idIncremental;
    printf("Ingrese la descripcion de la tarea:\n");
    fflush(stdin);
    char *descripcion = (char *) malloc(100 * sizeof(char));
    gets(descripcion);
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

void insertarNodo(Nodo **lista, Nodo *nuevoNodo){
    nuevoNodo->Siguiente = *lista; // El siguiente del nuevo nodo apunta al primer nodo de la lista
    *lista = nuevoNodo; // La lista ahora apunta al nuevo nodo
}

void listarTareas(Nodo **listaTareas){
    
    Nodo *auxiliar = *listaTareas;
    while (auxiliar != NULL)
    {
        printf("ID: %d, Descripcion: %s, Duracion: %d\n", auxiliar->Tarea.TareaID, auxiliar->Tarea.Descripcion, auxiliar->Tarea.Duracion);
        auxiliar = auxiliar->Siguiente;
    }
}



Nodo * buscarTarea(Nodo * tareas, int idTarea){
    Nodo *auxiliar = tareas;
    while (auxiliar != NULL && auxiliar->Tarea.TareaID != idTarea)
    {
        auxiliar = auxiliar->Siguiente;
    }
    return auxiliar;
}
