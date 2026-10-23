# Franco-C-Maximo-M---TP.-Grupal

DOCUMENTACIÓN DEL PROGRAMA.

REGISTRO DE AUTOS DE UNA CONCESIONARIA.

Trabajo práctico grupal - Programación I 

## **1. ¿DE QUÉ SE TRATA?**

Elegimos realizar un programa en C para registrar los autos de una concesionaria. La idea es que un empleado pueda cargar un vehículo y consultar los que ya están guardados. 

## **2. DATOS DE CADA AUTO**

Usamos una estructura llamada Auto para reunir los datos de un vehículo:

- Patente: texto de hasta 7 caracteres.
- Marca: texto de hasta 29 caracteres.
- Tipo: una letra, A para auto o C para camioneta. 
- Año: un número entero mayor que cero.
- Precio: un número que puede tener decimales y no puede ser negativo.
- Disponible: un dato booleano que indica si el vehículo está disponible para la venta.

## **3. OPCIONES DEL MENÚ**

Al iniciar, el programa muestra un menú. El usuario escribe el número de la opción que quiere utilizar.

1. Agregar un auto
    
Pide los datos del vehículo y los guarda en autos.txt. Los autos nuevos se agregan sin borrar los anteriores.

2. Listar autos
   
Muestra todos los autos guardados y la cantidad total que se mostró.

3. Listar autos de 2020 en adelante
   
Muestra solamente los vehículos del año 2020 en adelante. Ese año se define en la constante YEAR.

4. Buscar auto
   
Pide una patente y la compara con las guardadas. Si encuentra una coincidencia, muestra los datos de ese auto. Si no, avisa que no lo encontró.

5. Separar autos disponibles y no disponibles
   
Lee los autos y los guarda en dos archivos, disponible.txt y no_disponible.txt. El archivo original no cambia. Cada vez que se elige esta opción, se reemplaza el contenido anterior de esos dos archivos.

0. Salir

Termina el programa.

## **4. ¿CÓMO ESTÁ ORGANIZADO?**

Cada opción tiene su propia función. Esto permite dividir el código en tareas y encontrar más fácilmente cada parte.

En main usamos un do while para repetir el menú y un switch para ejecutar la opción elegida. 

Para preguntar  los autos, el programa los lee uno por uno desde el archivo.

## **5. ¿CÓMO SE GUARDAN LOS DATOS?**

Los datos se guardan en archivos de texto para que no se pierdan al cerrar el programa. En autos.txt se escribe un auto por línea, con los datos separados por espacios.

RT482BC Toyota C 2021 18500.00 1

En ese ejemplo, el último número indica que el auto está disponible: 1 significa sí y 0 significa no.

Usamos fopen para abrir los archivos, fprintf para escribir, fscanf para leer y fclose para cerrarlos. Si no se puede abrir un archivo, el programa muestra un mensaje.

## **6. INDICACIONES IMPORTANTES**

- Escribir la patente y la marca sin espacios, respetando límites.
- Usar punto para los decimales del precio, por ejemplo 15000.50.
- Al ingresar A o C para elegir el tipo de vehículo, se aceptan también minúsculas ya que se vuelven mayúsculas. 
- Ingresar 1 o 0 para indicar la disponibilidad.
- Al momento de buscar un vehículo, se escribe la patente con las mismas mayúsculas y minúsculas con las que se guardó.
- Al momento de buscar un vehículo, se debe escribir la patente respetando las mismas mayúsculas y minúsculas con las que se guardó. Por ejemplo, si la patente es AB123CD, se debe buscar como AB123CD y no como ab123cd, AB123cd etc.
- El programa controla algunos datos, que el año sea positivo, el precio no sea negativo y las opciones de disponibilidad.
- No es posible modificar ni eliminar autos ya cargados y se puede guardar una patente repetida.
