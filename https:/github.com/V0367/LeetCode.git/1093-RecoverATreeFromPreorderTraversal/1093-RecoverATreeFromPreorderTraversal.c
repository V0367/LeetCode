// Last updated: 07/08/2026, 15:39:41
char* STR; // our global ptr
typedef struct TreeNode Node; // shorten name

// return a new node
Node* newNode(int val) {
    Node* res = malloc(sizeof(Node));
    res -> val = val; res -> left = NULL; res -> right = NULL;
    return res;
}

// return next int in STR and increase STR
int getint() {
    int res = 0;
    for (; isdigit(*STR); ++STR) {
        res = res * 10 + *STR - '0';
    }
    return res;
}

// return the number of dashes in STR and increase STR
int getlevel() {
    int res = 0;
    for (; *STR == '-'; ++STR, ++res);
    return res; 
}

// return the next node in STR, with its child nodes being at nextLevel
Node* getNode(int nextLevel) {
    Node* res = newNode(getint());
    int i = getlevel();
    if (i == nextLevel) res->left = getNode(nextLevel + 1);
    else STR -= i; // cancel the getlevel()
    i = getlevel();
    if (i == nextLevel) res->right = getNode(nextLevel + 1);
    else STR -= i; // cancel the getlevel()
    return res;
}

struct TreeNode* recoverFromPreorder(char * traversal){
    STR = traversal;
    return getNode(1); 
}