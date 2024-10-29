#include <stdio.h>
#include <stdlib.h>
#define NUMNODES 100
struct Node {
	int info;	
    int count;        
	struct Node *left;	  
	struct Node *right; 
	struct Node *father; 
};
struct Node node[NUMNODES];

struct Node *avail = NULL;

void node_free(struct Node *p) {
    if (p != NULL) {
	    p->info = 0;
	    p->count = 0;
	    p->left = avail;
	    p->right = NULL;
	    p->father = NULL;
	    avail = p;
    }
}

struct Node *node_alloc() {
	struct Node *p = NULL;
	if (avail != NULL) {
		p = avail;
		avail = avail->left;
	}
	return p;
}

void tree_free(struct Node *p){
	if (p != NULL){
		if(p->left != NULL){
			tree_free(p->left);
		}
		if(p->right != NULL){
			tree_free(p->right);
		}
		node_free(p);
	}
}

struct Node makeTree(int info, struct Node *p){
	if (p != NULL){
		p->info = info;
		p->left = NULL;
		p->right = NULL;
		p->father = NULL;
	}
	return *p;
}

void setLeft(struct Node *p, struct Node *q){
	if (p != NULL && q != NULL){
		p->left = q;
		p->father = p;
	}
}

void setRight(struct Node *p, struct Node *q){
	if (p != NULL && q != NULL){
		p->right = q;
		p->father = p;
	}
}

void preOrdem(struct Node *p){
    if (p != NULL){
        printf("\n%d", p->info);
        preOrdem(p->left);
        preOrdem(p->right);
    }
}

void posOrdem(struct Node *p){
    if (p != NULL){
        posOrdem(p->left);
        posOrdem(p->right);
        printf("\n%d", p->info);
    }
}

void emOrdem(struct Node *p){
    if (p != NULL){
        emOrdem(p->left);
        printf("\n%d", p->info);
        emOrdem(p->right);
    }
}

int main() {
	avail = &node[0];
	for (int i = 0; i < NUMNODES - 1; i++) {
		node[i].info = 0;
		node[i].left = &node[i + 1];
		node[i].right = NULL;
		node[i].father = NULL;
	}
	node[NUMNODES - 1].left = NULL;
	
	struct Node r = makeTree(10, &r);
	struct Node a = makeTree(20, &a);
	struct Node b = makeTree(30, &b);
	struct Node c = makeTree(40, &c);
	struct Node d = makeTree(50, &d);
	struct Node e = makeTree(60, &e);
	struct Node f = makeTree(70, &f);
	struct Node g = makeTree(80, &g);
	struct Node h = makeTree(90, &h);
	struct Node i = makeTree(100, &i);
	struct Node j = makeTree(110, &j);
	
	setLeft(&r, &a);
	setRight(&r, &b);
	setLeft(&a, &c);
	setRight(&a, &d);
	setLeft(&b, &e);
	setLeft(&e, &f);
	setLeft(&f, &g);
	setRight(&g, &h);
	setLeft(&h, &i);
	setLeft(&i, &j);
	
	printf("\nPre ordem:");
	preOrdem(&r);
	printf("\nPos ordem:");
	posOrdem(&r);
	printf("\nEm ordem:");
	emOrdem(&r);
	
	return 0;
}
