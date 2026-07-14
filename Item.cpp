#include "Item.h"

Item::Item() : nome("Nenhum"), bonusAtaque(0) {}

Item::Item(std::string nome, int bonusAtaque) : nome(nome), bonusAtaque(bonusAtaque) {}

std::string Item::getNome() const { return this->nome; }
int Item::getBonusAtaque() const { return this->bonusAtaque; }