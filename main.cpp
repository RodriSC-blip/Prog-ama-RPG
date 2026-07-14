#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Combatente.h"
#include "Heroi.h"
#include "Monstro.h"
#include "Item.h"

using namespace std;

int main() {
    srand(time(0));

    vector<Combatente*> listaHerois;
    
    listaHerois.push_back(new Heroi("Thorin (Guerreiro)", 100, 20, 10, 5, Item("Machado de Ferro", 5)));
    listaHerois.push_back(new Heroi("Legolas (Arqueiro)", 80, 25, 5, 12, Item("Arco Elfico", 4)));
    listaHerois.push_back(new Heroi("Gandalf (Mago)", 70, 30, 3, 8, Item("Cajado de Luz", 8)));

    int ondasVencidas = 0;
    const int ALVO_VITORIA = 5;

    while (!listaHerois.empty() && ondasVencidas < ALVO_VITORIA) {
        system("cls");

        cout << "\n==================================================================\n";
        cout << "                  >>> ONDA DE MONSTROS NUMERO " << ondasVencidas + 1 << " <<<                     \n";
        cout << "==================================================================\n";

        int mHp = rand() % 50 + 40;
        int mAtk = rand() % 15 + 10;
        int mDef = rand() % 5 + 2;
        int mVel = rand() % 10 + 4;
        Combatente* monstro = new Monstro("Orc Emboscador", mHp, mAtk, mDef, mVel);

        cout << "\n[!] UM NOVO PERIGO SURGE DA ESCURIDAO:\n";
        cout << "    -> "; monstro->exibirStatus(); 
        cout << "\n------------------------------------------------------------------\n";

        cout << "\nRECRUTE SEU HEROI PARA O DUELO:\n\n";
        for (size_t i = 0; i < listaHerois.size(); ++i) {
            cout << "  [" << i << "] ";
            listaHerois[i]->exibirStatus(); 
        }

        int escolha;
        cout << ("\nDigite o numero correspondente: ");
        cin >> escolha;

        if (escolha < 0 || escolha >= static_cast<int>(listaHerois.size())) {
            cout << "\n[!] Escolha invalida! Turno desperdicado.\n\n";
            system("pause"); 
            delete monstro;
            continue; 
        }

        Combatente* heroi = listaHerois[escolha];
        int subTurno = 1;

        // Combate de Turno
        while (heroi->getHp() > 0 && monstro->getHp() > 0) {
            system("cls");
            cout << "==================================================================\n";
            cout << "         ROUND " << subTurno << " - CONFRONTO DIRETO INICIADO                     \n";
            cout << "==================================================================\n\n";

            // Troca de socos com espaçamentos claros
            if (heroi->getVelocidade() >= monstro->getVelocidade()) {
                cout << "  "; heroi->atacar(*monstro);
                if (monstro->getHp() > 0) {
                    cout << "  "; monstro->atacar(*heroi);
                }
            } else {
                cout << "  "; monstro->atacar(*heroi);
                if (heroi->getHp() > 0) {
                    cout << "  "; heroi->atacar(*heroi);
                }
            }
            
            cout << "\n------------------------------------------------------------------\n";
            cout << "STATUS APOS O ROUND:\n";
            cout << "  HEROI   => "; heroi->exibirStatus();
            cout << "  INIMIGO => "; monstro->exibirStatus();
            cout << "------------------------------------------------------------------\n";
            
            // Dados internos do sistema (Auditoria) mais discretos
            cout << "  "; AuditorJogo::auditarVidaRestante(*heroi);
            cout << "==================================================================\n\n";

            subTurno++;
            system("pause"); 
        }

        // Resolução do Duelo
        system("cls");
        cout << "==================================================================\n";
        cout << "                     FIM DO COMBATE DE ONDA                       \n";
        cout << "==================================================================\n\n";

        if (monstro->getHp() <= 0) {
            cout << "  [+] SUCESSO: O " << monstro->getNome() << " virou poeira!\n";
            ondasVencidas++;
        }
        delete monstro; 

        if (heroi->getHp() <= 0) {
            cout << "  [-] TRAGEDIA: O heroi " << heroi->getNome() << " foi derrotado!\n";
            delete heroi; 
            listaHerois.erase(listaHerois.begin() + escolha); 
        }

        cout << "\n==================================================================\n";
        system("pause"); 
    }

    // Tela de encerramento do jogo
    system("cls");
    cout << "\n==================================================================\n";
    if (listaHerois.empty()) {
        cout << "                    G A M E   O V E R !                           \n";
        cout << "          Todos os seus herois morreram bravamente.               \n";
        cout << "                Total de ondas limpas: " << ondasVencidas << "                  \n";
    } else {
        cout << "                    V I T O R I A !                               \n";
        cout << "       Parabens! Seus guerreiros purificaram a masmorra!          \n";
    }
    cout << "==================================================================\n\n";

    for (Combatente* h : listaHerois) {
        delete h;
    }

    return 0;
}