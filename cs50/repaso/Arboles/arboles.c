#include <stdio.h>
#include <stdlib.h>

// Definición del nodo del árbol
struct Node {
    int data;               // Valor en el nodo
    struct Node* left;      // Puntero al hijo izquierdo
    struct Node* right;     // Puntero al hijo derecho
};

// Función para crear un nuevo nodo
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));  // Reserva memoria para el nodo
    node->data = data;          // Asigna el valor
    node->left = NULL;          // Inicializa los punteros a NULL
    node->right = NULL;
    return node;                // Retorna el puntero al nuevo nodo
}

// Función para insertar un valor en el árbol
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        return newNode(data);  // Si no hay nodo, crea uno nuevo
    }

    if (data < node->data) {
        node->left = insert(node->left, data);  // Inserta en el subárbol izquierdo
    } else if (data > node->data) {
        node->right = insert(node->right, data);  // Inserta en el subárbol derecho
    }

    return node;  // Devuelve el puntero al nodo (puede ser el mismo o uno nuevo)
}

// Función para buscar un nodo en el árbol
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;  // Si el nodo es NULL o el valor es igual al del nodo actual, retorna el nodo
    }

    if (key < root->data) {
        return search(root->left, key);  // Busca en el subárbol izquierdo
    }

    return search(root->right, key);  // Busca en el subárbol derecho
}

// Función para eliminar un nodo en el árbol
struct Node* deleteNode(struct Node* root, int key) {
    // Caso base: Si el árbol está vacío
    if (root == NULL) return root;

    // Si el valor a eliminar es menor que el valor del nodo, va a la izquierda
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    // Si el valor a eliminar es mayor que el valor del nodo, va a la derecha
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    // Si el valor a eliminar es igual al valor del nodo, este es el nodo a eliminar
    else {
        // Nodo con solo un hijo o sin hijos
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);  // Libera la memoria del nodo eliminado
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);  // Libera la memoria del nodo eliminado
            return temp;
        }

        // Nodo con dos hijos: encuentra el sucesor en el subárbol derecho
        struct Node* temp = root->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }

        // Reemplaza el valor del nodo por el valor del sucesor
        root->data = temp->data;

        // Elimina el sucesor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;  // Devuelve el puntero al nodo modificado
}

// Función de recorrido en orden (in-order)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);            // Visita el subárbol izquierdo
        printf("%d ", root->data);      // Imprime el valor del nodo actual
        inorder(root->right);           // Visita el subárbol derecho
    }
}

// Función para liberar todo el árbol
void freeTree(struct Node* root) {
    if (root == NULL) return;

    // Primero libera los subárboles
    freeTree(root->left);
    freeTree(root->right);

    // Luego libera el nodo actual
    printf("Liberando nodo con valor: %d\n", root->data);  // Mensaje para visualizar la liberación
    free(root);
}

int main() {
    struct Node* root = NULL;  // Árbol inicialmente vacío

    // Inserta valores en el árbol
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Imprime el árbol en in-order
    printf("Recorrido in-order: ");
    inorder(root);
    printf("\n");

    // Búsqueda de un valor en el árbol
    struct Node* found = search(root, 40);
    if (found != NULL) {
        printf("Valor %d encontrado en el árbol.\n", found->data);
    } else {
        printf("Valor no encontrado en el árbol.\n");
    }

    // Elimina un valor del árbol
    root = deleteNode(root, 40);
    printf("Árbol después de eliminar 40: ");
    inorder(root);
    printf("\n");

    // Libera la memoria de todo el árbol
    freeTree(root);
    root = NULL;  // Establece el puntero a NULL después de liberar el árbol

    return 0;
}


