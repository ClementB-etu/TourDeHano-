/**
 * \file Game.hpp
 * \brief Définit la classe Game qui sera utilisé pour la résolution du problème.
 * \author Clément BELLEIL
 * \version 1
 * \date 23 Janvier 2022
 *
 * Classe Game pour représenter un Objet Game dans le problème des tours de Hanoï
 *
 */

#include <iostream>
#include<math.h>
#include "Tower.hpp"

/*!
\class Game
* Classe utilisée pour représenter les objets Game utilisés pour la résolution du problème
*/

class Game {
    private : 
        std::vector<Tower> myTowers; /*!< Vecteur contenant les différentes tours présentes dans la partie */
        int nbdisk; /*!< Nombre de disques présents dans la partie (pour résolution paire ou impaire) */
    public :
        std::vector<Disk> allDisks; /*!< Vecteur contenant les disques présents dans la partie (copie profonde pour appel à chaque disque pour mouvement) */
        Game();
        Game(int nbdisk);
        const void solve();
        void solvePair();
        void solveImpair();
        Tower* getTower(int i);
        int towerDestPair(Disk d);
        int towerDestImpair(Disk d);
        void setTower(Tower t);
        friend std::ostream& operator<<(std::ostream& out, const Game & g);
        ~Game();
};