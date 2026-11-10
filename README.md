*Este proyecto ha sido creado como parte del currículo de 42 por jmaestre.*

# Get Next Line

## 📝 Descripción
El objetivo fundamental del proyecto **Get Next Line** es programar una función en C que devuelva una línea leída desde un descriptor de archivo (*file descriptor* - `fd`). 

Llamar a la función `get_next_line` de manera repetida dentro de un bucle permite leer un archivo o la entrada estándar (`stdin`) línea por línea hasta llegar al final (`EOF`). Este proyecto introduce y profundiza en el uso crucial de las **variables estáticas** en C y el manejo eficiente de la memoria en el *heap*.

---

## 💡 Algoritmo y Decisión Técnica
El reto principal al implementar `get_next_line` consiste en gestionar lecturas en bloques de tamaño dinámico definido por la macro `BUFFER_SIZE`, sin perder los datos sobrantes leídos que pertenecen a líneas posteriores.

### Flujo del Algoritmo:
1. **Lectura y Acumulación**: Se lee del descriptor de archivo utilizando `read()` con el número de bytes indicado por `BUFFER_SIZE`. Lo leído se acumula en una **variable estática** persistente hasta encontrar un carácter de salto de línea (`\n`) o llegar al final del archivo (`EOF`).
2. **Extracción de la Línea**: Una vez localizado el `\n` (o final del buffer), se extrae la subcadena correspondiente a la línea actual (incluyendo el `\n`, si lo hay) para ser devuelta.
3. **Actualización del Buffer Restante**: La variable estática se actualiza para conservar únicamente los caracteres leídos que están después del `\n`, quedando lista para la próxima llamada a la función.
4. **Liberación de Memoria**: Si se produce un error o se alcanza el final del archivo y no quedan datos por devolver, se libera la memoria reservada y se resetea la variable estática a `NULL`.

---

## 🛠️ Instrucciones

### Estructura de Archivos
* `get_next_line.c`: Lógica principal de lectura, extracción y actualización.
* `get_next_line_utils.c`: Funciones auxiliares para manejo de cadenas y memoria (`ft_strlen`, `ft_strchr`, `ft_strjoin`, etc.).
* `get_next_line.h`: Archivo de cabecera con los prototipos de las funciones y librerías necesarias.

### Compilación y Uso
La función está diseñada para ser compilada e integrada junto con otros archivos de tu código fuente usando `gcc` o `cc` con los flags habituales y la definición opcional del `BUFFER_SIZE`:

```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl_test
```

Si no se especifica el indicador `-D BUFFER_SIZE=n`, el programa utilizará el valor predeterminado definido en `get_next_line.h`.

---

## 🎁 Parte Bonus

En los archivos `*_bonus.[c|h]`, el proyecto cumple los siguientes requisitos adicionales:
* **Gestión de una sola variable estática**.
* **Soporte para múltiples File Descriptors**: Capacidad de manejar múltiples descriptores de archivo de forma interactiva (por ejemplo, alternando entre el `fd 3`, `fd 4` y `fd 5`) sin perder el estado ni entremezclar las líneas leídas de cada uno. Esto se logra mediante un array de punteros estáticos indexados por el descriptor de archivo.

---

## 📚 Recursos y Uso de IA

### Referencias
* Documentación oficial de C: [Man page de `read(2)`](https://man7.org/linux/man-pages/man2/read.2.html).
* Tutoriales sobre gestión de memoria en C y variables estáticas (`static` storage class).

### Declaración del uso de IA
En cumplimiento de las directivas sobre el uso de Inteligencia Artificial del proyecto:
* **Uso de IA**: La IA fue utilizada principalmente para aclarar conceptos teóricos sobre la persistencia de las variables estáticas en el almacenamiento de memoria, debatir enfoques lógicos para evitar *leaks* de memoria en casos límite (*edge cases*), y estructurar este archivo de documentación.
* **Desarrollo de Código**: Toda la implementación lógica, estructura del algoritmo y depuración en C fueron escritas, probadas y razonadas personalmente sin generación automática de respuestas directas de código.