/*
 * DO NOT CHANGE CODE UNLESS SPECIFIED (such as TODOs)
 */
#include "operation_node.hpp"

template<typename T>
class MultiplicationNode : public OperationNode<T> {
public:
    T evaluate() override {
        T result = this->nodes[0]->evaluate(); // Initialize with the first node's evaluation
        // Loops through nodes and performs multiplication with the result
        for (std::size_t i = 1; i < this->nodes.size(); ++i) {
            result = result * this->nodes[i]->evaluate();
        }
        return result;// Returns final result of multiplication
    };

    MultiplicationNode(const std::vector<Node<T> *> &nodes) : OperationNode<T>(nodes) {}

    virtual ~MultiplicationNode() { // I got assistance from GPT writing this, used similar implementation for AdditionNode
        for (auto &node: this->nodes) {
            delete node;
        }
    }
};
