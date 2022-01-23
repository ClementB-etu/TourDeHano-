/**
 * \file Tower.hpp
 * \brief Définit la classe Tower qui sera utilisé pour la résolution du problème.
 * \author Clément BELLEIL
 * \version 1
 * \date 23 Janvier 2022
 *
 * Classe Tower pour représenter un Objet Tower dans le problème des tours de Hanoï
 *
 */

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Disk.hpp"

/*!
\class Tower
* Classe utilisée pour représenter les objets Tower utilisés pour la résolution du problème
*/
class Tower{
    private :
        std::string name; /*!< Nom de la tour (pour affichage) */
        std::vector<Disk> myDisks; /*!< Vecteur des disques présents sur la tour */
    public :
        Tower();
        Tower(std::string name);
        std::string getName();
        bool isEmpty();
        bool isPossible(Disk d);
        Disk popDisk();
        void removeDisk();
        void pushDisk(Disk d);
        bool containsFirst(Disk d);
        bool contains(Disk d); //Essentiellement pour le debug
        friend std::ostream& operator<<(std::ostream& out, const Tower & t);
};