## unique_ptr_1.cc:
En este código se define una clase llamada Human que tiene dos atributos: name (nombre) y age (edad). La clase tiene un constructor que inicializa los atributos y muestra un mensaje indicando que se ha creado un objeto Human. También tiene un destructor que muestra un mensaje indicando que el objeto Human ha sido destruido.

La clase Human tiene un método llamado magicAge() que realiza una operación en la edad del objeto Human basada en la primera letra del nombre. Luego, hay una función llamada do_math() que recibe un puntero único (unique_ptr) a un objeto Human y llama al método magicAge() del objeto.

En la función do_work(), se crea un puntero único (unique_ptr) llamado human que apunta a un objeto Human creado mediante la función make_unique(). Luego, se llama a la función do_math() pasando el puntero human como argumento. Finalmente, se devuelve la edad del objeto Human al finalizar la función.

En la función main(), se llama a do_work() y se almacena el valor devuelto en la variable magic. Luego, se muestra en la consola el valor de magic.

## unique_ptr_2.cc:
Este código es similar al anterior, pero presenta algunas diferencias. La función create_human() ahora devuelve un puntero único (unique_ptr) en lugar de un entero. Se crea un objeto Human dentro de create_human() y se devuelve como un puntero único sin necesidad de utilizar std::move().

La función do_work() ahora utiliza la función create_human() para obtener un puntero único a un objeto Human. Luego, se llama al método magicAge() del objeto y se muestra en la consola el valor de human->age.

En la función main(), se llama a do_work().

## unique_ptr_3.cc:
En este código, se define un vector llamado source que contiene los números del 1 al 5. Se muestra en la consola el tamaño del vector source y la dirección de memoria donde se encuentra almacenado.

Luego, se crea otro vector llamado destination utilizando std::move(source). Esto hace que destination adquiera la propiedad de los elementos de source, dejando source en un estado válido pero vacío.

Se muestra en la consola el tamaño de source (que ahora es 0) y la dirección de memoria donde se encuentra. También se muestra el tamaño de destination (que ahora es 5) y la dirección de memoria donde se encuentra.

## unique_ptr_4.cc:
En este código se define una clase llamada Person que tiene un atributo name de tipo string. La clase tiene un constructor que recibe un argumento new_name y lo mueve al atributo name utilizando std::move(). Se muestra en la consola un mensaje indicando que se ha creado un objeto Person.

En la función main(), se crea una variable name de tipo string con el valor "Adri". Luego, se crea un objeto Person llamado person utilizando el valor de name moviéndolo al constructor.

Después de crear el objeto person, se muestra en la consola el valor de name, que ahora es una cadena vacía debido a que su contenido fue movido al objeto person.