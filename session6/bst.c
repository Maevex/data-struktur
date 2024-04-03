#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

Node* minValueNode(Node* node) {
    Node* current = node;

    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

int main() {
    Node* root = NULL;
    int data;
    char choice;
    int key;

    do {
        printf("\nMenu:\n");
        printf("1. Tambahkan data baru\n");
        printf("2. Hapus data\n");
        printf("3. Cari data\n");
        printf("4. Inorder traversal\n");
        printf("5. Preorder traversal\n");
        printf("6. Postorder traversal\n");
        printf("7. Keluar\n");
        printf("Pilihan Anda: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                printf("Masukkan nilai data baru: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case '2':
                printf("Masukkan nilai data yang ingin dihapus: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case '3':
                printf("Masukkan nilai data yang ingin dicari: ");
                scanf("%d", &key);
                Node* found = search(root, key);
                if (found != NULL) {
                    printf("%d ditemukan dalam TREE.\n", key);
                } else {
                    printf("%d tidak ditemukan dalam TREE.\n", key);
                }
                break;
            case '4':
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case '5':
                printf("Preorder traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case '6':
                printf("Postorder traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case '7':
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih lagi.\n");
        }
    } while (choice != '7');

    return 0;
}