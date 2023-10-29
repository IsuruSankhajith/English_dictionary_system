#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <unordered_map>

class Word {
public:
    Word(const std::string& name = "", const std::string& type = "", const std::string& definition = "");

    std::string getName() const;
    void setName(const std::string& name);

    std::string getType() const;
    void setType(const std::string& type);

    std::string getDefinition() const;
    void setDefinition(const std::string& definition);

    void printDefinition() const;

private:
    std::string name_;
    std::string type_;
    std::string definition_;

    static const std::unordered_map<std::string, std::string> type_map;
};

Word::Word(const std::string& name, const std::string& type, const std::string& definition)
        : name_(name), type_(type), definition_(definition)
{
}

std::string Word::getName() const {
    return name_;
}

void Word::setName(const std::string& name) {
    name_ = name;
}

std::string Word::getType() const {
    return type_;
}

void Word::setType(const std::string& type) {
    type_ = type;
}

std::string Word::getDefinition() const {
    return definition_;
}

void Word::setDefinition(const std::string& definition) {
    definition_ = definition;
}

void Word::printDefinition() const {
    std::cout << "Name: " << name_ << std::endl;
    auto typeIt = type_map.find(type_);
    if (typeIt != type_map.end()) {
        std::cout << "Type: " << type_ << " " << typeIt->second << std::endl;
    } else {
        std::cout << "Type: " << type_ << std::endl;
    }
    std::cout << "Definition: " << definition_ << std::endl;
}

const std::unordered_map<std::string, std::string> Word::type_map = {
    {"noun", "[noun]"},
    {"verb", "[verb]"},
    {"adverb", "[adverb]"},
    {"adjective", "[adjective]"},
    {"preposition", "[preposition]"},
    {"miscellaneous", "[miscellaneous]"},
    {"proper noun", "[proper noun]"},
    {"noun and verb", "[noun and verb]"},
};

#endif  // WORD_H
