#include "Tree.hpp"
#include "TreeNode.hpp"
#include <iostream>
#include <stddef.h>

Tree::Tree() { this->rootnode = NULL; }

Tree::Tree(int data) {
    TreeNode *node = new TreeNode(data);
    this->rootnode = node;
}

void Tree::insert(int data) {
    TreeNode *node = new TreeNode(data);
    TreeNode *cursor = this->rootnode;

    if (cursor == NULL) {
        this->rootnode = node;
        return;
    }

    while (1) {
        int value = cursor->getData();
        if (value < data) {
            if (cursor->getRight() == NULL) {
                cursor->setRight(node);
                break;
            } else {
                cursor = cursor->getRight();
            }
        } else {
            if (cursor->getLeft() == NULL) {
                cursor->setLeft(node);
                break;
            } else {
                cursor = cursor->getLeft();
            }
        }
    }
    return;
}

void Tree::display() {
    display(this->rootnode);
    return;
}

void Tree::display(TreeNode *curNode) {
    if (curNode == NULL)
        return;
    display(curNode->getLeft());
    std::cout << " ";
    std::cout << curNode->getData();
    display(curNode->getRight());
}

bool Tree::search(int data) {

    TreeNode *cursor = this->rootnode;

    while (cursor != NULL) {
        if (cursor->getData() == data) {
            std::cout << cursor->getData() << " ";
            std::cout << "' " << data << " search success! '" << std::endl;
            return true;
        } else if (cursor->getData() > data) {
            std::cout << cursor->getData() << " ";
            cursor = cursor->getLeft();
        } else {
            std::cout << cursor->getData() << " ";
            cursor = cursor->getRight();
        }
    }

    std::cout << "' " << data << " search Failed '" << std::endl;
    return false;
}

bool Tree::Is_There(int item) {

    TreeNode *Cur = this->rootnode;
    while (1) {
        if (Cur->getData() == item) {
            return true;
        }
        if (Cur->getData() < item) {
            if (Cur->getRight() == NULL)
                return false;
            Cur = Cur->getRight();
        } else {
            if (Cur->getLeft() == NULL)
                return false;
            Cur = Cur->getLeft();
        }
    }
}

void Tree::remove(int key) {
    TreeNode *Cur2 = NULL;
    TreeNode *Cur = this->rootnode;
    TreeNode *Par_Parent = NULL;
    TreeNode *Parent = NULL;
    TreeNode *Child = NULL;

    if (!(this->Is_There(key))) {
        std::cout << key << " remove failed" << std::endl;
        return;
    }

    while (Cur->getData() != key) {
        if (key > Cur->getData()) {
            Par_Parent = Parent;
            Parent = Cur;
            Cur = Cur->getRight();
        } else {
            Par_Parent = Parent;
            Parent = Cur;
            Cur = Cur->getLeft();
        }
    }

    if (Cur->getLeft() == NULL && Cur->getRight() == NULL) {
        if (Parent == NULL) {
            Cur->setData(NULL);
        } else {
            if (Parent->getLeft() == Cur) {
                Parent->setLeft(NULL);
            }
            if (Parent->getRight() == Cur) {
                Parent->setRight(NULL);
            }
        }
        delete (Cur);
        return;
    }

    else if (Cur->getLeft() == NULL || Cur->getRight() == NULL) {

        Child = (Cur->getLeft() != NULL) ? Cur->getLeft() : Cur->getRight();
        if (Parent == NULL) {
            Cur = Child;
        } else {
            if (Parent->getLeft() == Cur) {
                Parent->setLeft(Child);
            } else {
                Parent->setRight(Child);
            }
        }
        delete (Cur);
        return;
    }

    else {
        Parent = Cur;
        Cur2 = Cur->getRight();

        while (Cur2->getLeft() != NULL) {
            Parent = Cur2;
            Cur2 = Cur2->getLeft();
        }

        if (Parent->getLeft() == Cur2) {
            Parent->setLeft(Cur2->getRight());
        } else {
            Parent->setRight(Cur2->getRight());
        }
        Cur->setData(Cur2->getData());
        delete (Cur2);
        return;
    }
    return;
}
