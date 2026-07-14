#ifndef HEROI_H
#define HEROI_H

#include "Combatente.h"
#include "Item.h"

class Heroi : public Combatente {
private:
    Item itemEquipado; // Relação de Composição ("Tem um")

public:
    Heroi();
    Heroi(std::string nome, int hp, int ataque, int defesa, int velocidade, Item item);

    // Sobrescrita Polimórfica (override)
    void atacar(Combatente &alvo) override;
    void exibirStatus() const override;
};

#endif