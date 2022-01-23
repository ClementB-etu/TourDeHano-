/**
 * \file Disk.hpp
 * \brief Définit la classe Disk qui sera utilisé pour la résolution du problème.
 * \author Clément BELLEIL
 * \version 1
 * \date 23 Janvier 2022
 *
 * Classe Disk pour représenter un Objet Disk dans le problème des tours de Hanoï
 *
 */

#pragma once
#include <iostream>

/*!
\class Disk
* Classe utilisée pour représenter les objets Disk utilisés pour la résolution du problème
*/
class Disk {
    private : 
        int diameter; /*!< Diamètre du disque */
    public :
        int getDiameter();
        Disk();
        Disk(int diam);
        friend std::ostream& operator<<(std::ostream& out, const Disk & d);
};