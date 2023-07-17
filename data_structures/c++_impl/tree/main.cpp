#include <iostream>
#include "tree.h"

int main() {

    Tree<float> tree;
    tree.add(8);
    tree.add(4);
    tree.add(9);
    tree.add(3);
    tree.add(7);
    tree.add(10);
    tree.add(1);
    tree.add(3.5);

    std::cout<<"---------DFS----------"<<"\n";
    tree.DFS();
    std::cout<<"---------BFS----------"<<"\n";
    tree.BFS();
    std::cout<<"-------depth of tree....."<<"\n";
    std::cout<<tree.depth()<<"\n";
    std::cout<<"-------diameter of tree....."<<"\n";
    std::cout<<tree.diameter()<<"\n";
    std::cout<<"-------traverse in ascending order....."<<"\n";
    tree.inOreder();

  
}
