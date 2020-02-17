fndef TREE_H
#define TREE_H
class Tree{
    private:
        Node * root;
        int depth;
    public:
        Tree();
        void generate_Tree(int depth); //Generates tree unitl depth d is reached
        void generate_Tree(); //Generates tree until goal node is generated
        void print_Tree(); //Prints the tree in console - no longer needed as i have shifted to GUI
        Node *getTree();
};



#endif
