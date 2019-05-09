#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

int menuDeOpciones(char mensaje[]);


/** \brief Inicializa el estado de los empleados
 *
 * \param Employee* puntero a array de employees
 * \param int el tamaño del array de employees
 * \return int  retorna -1 si no pudo inicializar el estado, 0 si puedo inicializarlos.
 *
 */
int initEmployees(Employee*,int);

/** \brief harcode de empleados
 *
 * \param Employee* puntero a array de employees
 * \param int tamaño del array de empleados
 * \return void
 *
 */
void hardcodeEmployees(Employee*,int);


/** \brief Agrega un employee al array
 *
 * \param Employee* puntero al array de employee
 * \param int tamaño del array
 * \return int retorna -1 si hay error, 0 si esta todo ok
 *
 */
int addEmployee(Employee*,int);


/** \brief Busca el primer espacio libre en el array de employees.
 *
 * \param Employee* puntero al array de employees
 * \param int tamaño del array employees
 * \return int retorna el indice del lugar libre en el array, sino hay retorna -1.
 *
 */
int buscarEspacioLibre(Employee*,int);

/** \brief Busca un empleado por id
 *
 * \param Employee* puntero al array de employees
 * \param len int  tamaño del array employees
 * \param id int id a buscar en el array
 * \return int retorna el id
 *
 */
int findEmployeeById(Employee*,int len,int id);

/** \brief Borra un empleado logicamente
 *
 * \param Employee*  puntero al array de employees
 * \param len int tamaño del array employees
 * \param id int id a borrar.
 * \return int retorna 0 si se borro el empleado, 1 si se cancelo la baja del usuario.
 *
 */
int removeEmployee(Employee*,int len,int id);


/** \brief Modifica algun campon del empleado
 *
 * \param Employee*  puntero al array de employees
 * \param int tamaño del array
 * \return int -1 si no se modifico, 0 si se modifico el empleado.
 *
 */
int modifyEmployee(Employee*, int);

/** \brief Ordena los elementos del array employee, el parametro order indica el orden en el que se ordena el array.
 *
 * \param Employee* puntero al array de employees
 * \param len int tamaño del array de empleados
 * \param order int  Criterio en el que se ordenan los empleados, 1 ascendente, 0 descendente
 * \return int retorna -1 si hay algun error, 0 si esta todo bien.
 *
 */
int sortEmployees(Employee*,int len,int order);

/** \brief Muesta un empleado
 *
 * \param Employee estructura employee
 * \return void no retorna nada
 *
 */
void mostrarUnEmployee(Employee);

/** \brief Muestra un array de empleados
 *
 * \param Employee* puntero a array de employees
 * \param int tamaño del array de empleados
 * \return int retorna 0 si pudo mostrar, -1 si no pudo.
 *
 */
int printEmployees(Employee*,int);

/** \brief Calcula el promedio total de los salarios de los empleados y cuantos superan el promedio del total
 *
 * \param Employee*  puntero al array de employees
 * \param len int tamaño del array de employees
 * \return int -1 si ocurrio un error, 0 si esta todo bien
 *
 */
int calcularPromedio(Employee*,int len);


