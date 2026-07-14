#ifndef COMBATENTE_H
#define COMBATENTE_H

#include <string>
#include <iostream>

// Declaramos que a classe existe
class AuditorJogo;

class Combatente {
protected: 
    const std::string nome;
    int hp;
    int ataque;
    int defesa;
    int velocidade;

public:
    Combatente();
    Combatente(std::string nome, int hp, int ataque, int defesa, int velocidade);
    virtual ~Combatente(); 

    std::string getNome() const;
    int getHp() const;
    int getAtaque() const;
    int getDefesa() const;
    int getVelocidade() const;
    void setHp(int hp);

    virtual void atacar(Combatente &alvo) = 0; 
    virtual void receberDano(int danoInimigo);
    virtual void exibirStatus() const;

    // Declaração de amizade
    friend class AuditorJogo; 
};

// Definição da classe amiga aqui mesmo (Inline), sem precisar de um .cpp para ela!
class AuditorJogo {
public:
    static void auditarVidaRestante(const Combatente &c) {
        // Acessa o atributo protegido '.hp' diretamente por ser friend
        std::cout << "[AUDITORIA] " << c.nome << " HP interno: " << c.hp << "\n";
    }
};

#endif