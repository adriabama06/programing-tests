#include <stdio.h>
#include <stdlib.h>
#include <arm_neon.h>

/*
Dentro de la función, se realiza un bucle para procesar los elementos de los vectores en grupos de 4.
Esto se debe a que las instrucciones NEON pueden realizar operaciones en paralelo en registros vectoriales de 128 bits que contienen 4 elementos de punto flotante de 32 bits.

*/
void vector_add(float* a, float* b, float* result, int size) {
    // Dentro del bucle, se cargan los valores de los vectores a y b utilizando la función vld1q_f32,
    // que carga 4 elementos de punto flotante de 32 bits de memoria en un registro vectorial.
    for (int i = 0; i < size; i += 4) {
        float32x4_t va = vld1q_f32(a + i);
        float32x4_t vb = vld1q_f32(b + i);
        // Luego, se realiza la suma vectorial utilizando la función vaddq_f32,
        // que suma los elementos correspondientes de los dos registros vectoriales y almacena el resultado en otro registro vectorial.
        float32x4_t vr = vaddq_f32(va, vb);
        // Finalmente, el resultado se guarda en memoria utilizando la función vst1q_f32,
        // que almacena los elementos del registro vectorial en la dirección de memoria especificada por el puntero result.
        vst1q_f32(result + i, vr);
    }
}

int main() {
    const float addition = 1.64f;
    const int size = 8;  // Tamaño de los vectores

    float* vectorA = (float*) malloc(sizeof(float) * size);
    float* vectorB = (float*) malloc(sizeof(float) * size);

    float* vectorResult = (float*) malloc(sizeof(float) * size);
    
    vectorA[0] = addition;
    vectorB[0] = addition * 2;
    
    for (int i = 1; i < size; i++)
    {
        vectorA[i] = addition + (vectorB[i - 1] * (5/4));
        vectorB[i] = addition + (vectorA[i - 1] * (5/4));
    }

    // Sumar los vectores A y B
    vector_add(vectorA, vectorB, vectorResult, size);
    
    // Imprimir el resultado
    printf("Vector A:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f, ", vectorA[i]);
    }
    printf("\n");

    printf("Vector B:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f, ", vectorB[i]);
    }
    printf("\n");

    printf("Vector Result:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f, ", vectorResult[i]);
    }
    printf("\n");
    
    return 0;
}
