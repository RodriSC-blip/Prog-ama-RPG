#ifndef MONSTRO_H
#define MONSTRO_H

#include "Combatente.h"

class Monstro : public Combatente {
public:
    Monstro();
    Monstro(std::string nome, int hp, int ataque, int defesa, int velocidade);

    void atacar(Combatente &alvo) override;
    void exibirStatus() const override;
};

#endif