
void TreapInsert(BST *T, int key,int priority){
    TreeNode *z = newNode(key,priority);
    TreeNode *y = NULL;
    TreeNode *x = T->root;
    
    while(x != NULL){
        y = x;
        if(key<(x->key)){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    z->parent = y;
    if(y==NULL){
        T->root = z;
    }else if((z->key) < (y->key)){
        y->left = z;
    }else{
        y->right = z;
    }
    
    //Effettuo le rotazioni
    while(z->parent != NULL && (z->priority)<((z->parent)->priority)){
        TreeNode *p = z->parent;
        z->parent = p->parent; 
        p->parent = z;
        
        if(z->parent != NULL){
            if(z->parent->left == p){
                z->parent->left = z;
            }else{
                z->parent->right = z;
            }
        }else{
            T->root = z;
        }
        
        if(z == p->left){   //Left son
            RightRotate(z,p);
        }else{              //Right Son
            LeftRotate(z,p);
        }
    }
    
}

void RightRotate(TreeNode *z,TreeNode *p){
    TreeNode *right_son = z->right;
    z->right = p;
    p->left = right_son;
    if(right_son != NULL) right_son->parent = p;
}

void LeftRotate(TreeNode *z,TreeNode *p){
    TreeNode *left_son = z->left;
    z->left = p;
    p->right = left_son;
    if(left_son != NULL) left_son->parent = p;
}
