/*
 * DO NOT CHANGE CODE UNLESS SPECIFIED (such as TODOs)
 */
#pragma once

#include <string>
#include <vector>
#include "node.hpp"
#include "value_node.hpp"
#include "multiplication_node.hpp"
#include "addition_node.hpp"
#include "util.hpp"

template<typename T>
class Formula {
private:
    std::string formula_str;
    Node<T> *formula;
    std::vector<ValueNode<T> *> variables;

public:
    Formula(const std::string &formula_str) : formula_str(formula_str) {

        // Splits the string into parts based on '+' operator
        std::vector<std::string> adders;
        split_string(formula_str, '+', adders);

        // Creates vector to hold nodes for addition elements
        std::vector<Node<T> *> addition_elements;

        //Iterates over each part resulting from split by '+'
        for (auto adder: adders) {
            // Checks if the part does not contain '*' operator
            if (!containsAsterisk(adder)) {
                auto *valueNode = new ValueNode<T>(); // Creates new value node
                variables.push_back(valueNode); // Stores the node in variables
                addition_elements.push_back(valueNode);// Adds the node to addition elements
                continue;
            }

            // If part contains '*' operator, split further by '*'
            std::vector<std::string> multipliers;
            std::vector<Node<T> *> multiplication_elements;

            // Creates vector to hold nodes for multiplication elements
            split_string(adder, '*', multipliers);

            // Create value nodes for each part resulting from split by '*'
            for (auto multiplier: multipliers) {
                auto *valueNode = new ValueNode<T>(); // Create new value node
                variables.push_back(valueNode); // Store node in variables
                multiplication_elements.push_back(valueNode); // Add the node to multiplication elements
            }

            // Creates multiplication node from multiplication elements and adds it into addition_elements
            addition_elements.push_back(new MultiplicationNode<T>(multiplication_elements));
        }
        // Creates root addition node from addition_elements
        formula = new AdditionNode<T>(addition_elements);
    };

    T calculate(const std::vector<T> &values) {
        for (std::size_t i = 0; i < values.size(); i++) {
            variables[i]->setValue(values[i]);
        }
        return formula->evaluate();
    };

    ~Formula() { // Kevin helped me work through this solution.
//        for (auto &variable: this->variables) { // If including 'delete formula', this line of code results in attempted double deletion of the nodes because the nodes in variables are the same child nodes being handled by addition_node and multiplication_node's respective destructors. Without 'delete formula', the child nodes are deleted, but the root node is not. To resolve the issue, this destructor should only handle deallocating memory for the root node 'formula'.
//            delete variable;
//        }
        delete formula;
    };
};