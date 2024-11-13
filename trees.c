#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insertnode(struct node* root, int data) {
    if (root == NULL) {
        return createnode(data);
    }

    if (data > root->data) {
        root->right = insertnode(root->right, data);
    } else if (data < root->data) {
        root->left = insertnode(root->left, data);
    }

    return root;
}

void inordertraversal(struct node* root) {
    if (root != NULL) {
        inordertraversal(root->left);
        printf("%d ", root->data);
        inordertraversal(root->right);
    }
}

void preordertraversal(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preordertraversal(root->left);
        preordertraversal(root->right);
    }
}

void postordertraversal(struct node* root) {
    if (root != NULL) {
        postordertraversal(root->left);
        postordertraversal(root->right);
        printf("%d ", root->data);
    }
}

struct node* minvalue(struct node* root) {
    struct node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct node* deletenode(struct node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deletenode(root->left, key);
    } else if (key > root->data) {
        root->right = deletenode(root->right, key);
    } else {
        

        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minvalue(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }

    return root;
}

int height(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int balanceFactor(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    return height(root->left) - height(root->right);
}

int main() {
    struct node* root = NULL;

    root = insertnode(root, 50);
    root = insertnode(root, 30);
    root = insertnode(root, 20);
    root = insertnode(root, 40);
    root = insertnode(root, 70);
    root = insertnode(root, 60);
    root = insertnode(root, 80);

    printf("Inorder traversal of the given tree: \n");
    inordertraversal(root);
    printf("\n");

    printf("Deleting node 20\n");
    root = deletenode(root, 20);
    printf("Inorder traversal after deletion: \n");
    inordertraversal(root);
    printf("\n");

    printf("Deleting node 30\n");
    root = deletenode(root, 30);
    printf("Inorder traversal after deletion: \n");
    inordertraversal(root);
    printf("\n");

    printf("Deleting node 50\n");
    root = deletenode(root, 50);
    printf("Inorder traversal after deletion: \n");
    inordertraversal(root);
    printf("\n");

    return 0;
}