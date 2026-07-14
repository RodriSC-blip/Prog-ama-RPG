#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
private:
    std::string nome;
    int bonusAtaque;

public:
    Item(); 
    Item(std::string nome, int bonusAtaque); 
    
    std::string getNome() const;
    int getBonusAtaque() const;
};

#endif