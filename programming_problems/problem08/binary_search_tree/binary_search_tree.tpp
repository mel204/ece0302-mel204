#include "binary_search_tree.hpp"

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree()
{
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(
    const BinarySearchTree<KeyType, ItemType>& rhs)
{
    root = 0;
    Node<KeyType, ItemType>** lhs = &root;

    std::stack<stackvar<KeyType, ItemType>> s;

    stackvar<KeyType, ItemType> rootvar;
    rootvar.rhs = rhs.root;
    rootvar.lhs = lhs;
    s.push(rootvar);

    while (!s.empty()) {
        stackvar<KeyType, ItemType> currentvar = s.top();
        s.pop();

        Node<KeyType, ItemType>* curr_rhs = currentvar.rhs;
        Node<KeyType, ItemType>** curr_lhs = currentvar.lhs;

        if (curr_rhs == 0)
            continue;

        // allocate new node and copy contents
        Node<KeyType, ItemType>* temp = new Node<KeyType, ItemType>;
        temp->key = curr_rhs->key;
        temp->data = curr_rhs->data;
        temp->left = 0;
        temp->right = 0;
        *curr_lhs = temp;

        // push left subtree
        currentvar.rhs = curr_rhs->left;
        currentvar.lhs = &((*curr_lhs)->left);
        s.push(currentvar);

        // push right subtree
        currentvar.rhs = curr_rhs->right;
        currentvar.lhs = &((*curr_lhs)->right);
        s.push(currentvar);
    }
}


template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>& BinarySearchTree<KeyType, ItemType>::
operator=(BinarySearchTree<KeyType, ItemType> rhs)
{
    swap(rhs);
    return *this;
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::swap(BinarySearchTree<KeyType, ItemType>& rhs)
{
    std::swap(root, rhs.root);
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree()
{
    destroy();
}


template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroy()
{
    std::stack<Node<KeyType, ItemType>*> s;
    s.push(root);

    while (!s.empty()) {
        Node<KeyType, ItemType>* curr = s.top();
        s.pop();

        if (curr != 0) {
            s.push(curr->left);
            s.push(curr->right);
            delete curr;
        }
    }
    root = 0;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::insert(
    const KeyType& key, const ItemType& item)
{
    // TODO 
    // create new node with data
    Node<KeyType, ItemType>* newNode = new Node<KeyType, ItemType>;
    newNode->key = key;
    newNode->data = item;

    Node<KeyType, ItemType>* curr = root;
    Node<KeyType, ItemType>* curr_parent = 0;

    if (isEmpty())
    {
        root = newNode;
        newNode = nullptr;
        return true;
    }

    //search will find the correct position based off of the key
    search(key, curr, curr_parent);

    //make sure curr is null meaning item doesn't exist
    if (curr->key == key && curr->data == item)
    {
        return false;
    }

    while(curr != nullptr)
    {
        //find the key
        if(key == curr->key)
            return false;

        if(key > curr->key)
        {
            curr_parent = curr;
            curr = curr->right;
        } else
        {
            curr_parent = curr;
            curr = curr->left;
        }
    }

    //insert new node

    if (key < curr_parent->key)
        curr_parent->left = newNode;
    else
        curr_parent->right = newNode;
    
    //success
    return true;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty()
{
    return (root == 0);
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::retrieve(
    const KeyType& key, ItemType& item)
{
    Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    search(key, curr, curr_parent);

    if (curr == 0)
        return false;

    if (curr->key == key) {
        item = curr->data;
        return true;
    }

    return false;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::remove(KeyType key)
{
    if (isEmpty())
        return false; // empty tree

    // TODO

    //search for key
    Node<KeyType, ItemType>* curr = root;
    Node<KeyType, ItemType>* curr_parent = 0;

    search(key, curr, curr_parent);

    // case one thing in the tree

    if(curr == root && curr->left == nullptr && curr->right == nullptr)
    {
        //remove the item
        delete curr;
        root = nullptr;
        return true;
    }

    // case, found deleted item at leaf
    if((curr->left == nullptr && curr->right == nullptr))
    {
        //remove the item
        if(curr == curr_parent->left)
        {
            curr_parent->left = nullptr;
        } else
        {
            curr_parent->right = nullptr;
        }
        return true;
    }
    // case, item to delete has only a right child
    if((curr->left == nullptr && curr->right != nullptr))
    {
        //replace with child
        if(curr == root)
        {
            root = curr->right;
        } else if(curr == curr_parent->left)
        {
            curr_parent->left = curr->right;
        } else
        {
            curr_parent->right = curr->right;
        }
        delete curr;
        return true;
    }
    // case, item to delete has only a left child
    if((curr->right == nullptr && curr->left != nullptr))
    {
        //replace with child
        if(curr == root)
        {
            root = curr->left;
        } else if(curr == curr_parent->left)
        {
            curr_parent->left = curr->left;
        } else
        {
            curr_parent->right = curr->left;
        }
        delete curr;
        return true;
    }
    // case, item to delete has two children
    if((curr->left != nullptr && curr->right != nullptr))
    {
        Node<KeyType, ItemType>* temp = curr->right;
        Node<KeyType, ItemType>* temp_parent = curr;

        //find successor
        while(temp->left != nullptr)
        {
            temp_parent = temp;
            temp = temp->left;
        }
        //update curr
        curr->data = temp->data;
        curr->key = temp->key;  
        //update parent
        if(temp == temp_parent->right)
            temp_parent->left = temp->right;
        else 
            temp_parent->right = temp->right;

        //delete the node
        delete temp;
        return true;
    }

    return false; // default should never get here
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorder(Node<KeyType, ItemType>* curr,
    Node<KeyType, ItemType>*& in, Node<KeyType, ItemType>*& parent)
{
    // TODO: find inorder successor of "curr" and assign to "in"

    // if curr is empty exit
    if (curr == nullptr)
        return;
    // recursively call with left as parent
    inorder(curr, in, curr->left);

    if (in == nullptr || in->key < curr->key)
        // if greater then go right
        inorder(curr, curr, curr->right);
    else
        // otherwise send in parent as curr
        inorder(parent, in, curr);

}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::search(KeyType key,
    Node<KeyType, ItemType>*& curr, Node<KeyType, ItemType>*& parent)
{
    curr = root;
    parent = 0;

    if (isEmpty())
        return;

    while (true) {
        if (key == curr->key) {
            break;
        } else if (key < curr->key) {
            if (curr->left != 0) {
                parent = curr;
                curr = curr->left;
            } else
                break;
        } else {
            if (curr->right != 0) {
                parent = curr;
                curr = curr->right;
            } else
                break;
        }
    }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::treeSort(KeyType arr[], int size) {
    // TODO: check for duplicate items in the input array

    // TODO: use the tree to sort the array items

    // TODO: overwrite input array values with sorted values
}
