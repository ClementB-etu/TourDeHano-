/**
 * \file Disk.cpp
 * \brief Définit les fonctions de la classe Disk qui seront utilisées pour la résolution du problème.
 * \author Clément BELLEIL
 * \version 1
 * \date 23 Janvier 2022
 *
 * Définition des fonctions utiles à l'utilisation des objets de la classe Disk
 *
 */

#include "Disk.hpp"

/**
 * \fn Disk()
 * \brief Constructeur par défaut d'un objet Disk.
 * 
 *  \return Instance nouvelle allouée d'un objet de type Disk.
 */
Disk::Disk(){
    this->diameter = 0;
}

/**
 * \fn Disk(int diam)
 * \brief Constructeur d'un objet Disk en renseignant son diamètre.
 *
 * \param diam diamètre de l'objet disque à créer.
 * \return Instance nouvelle allouée d'un objet de type Disk.
 */
Disk::Disk(int diam){
    this->diameter = diam;
}

/**
 * \fn getDiameter()
 * \brief retourne le diamètre de l'objet Disk
 *
 * \return diamètre du disque
 */
int Disk::getDiameter() {
    return this->diameter;
}

/**
 * \fn std::ostream& operator<<(std::ostream& out, const Disk & d)
 * \brief redéfinit l'opérateur "<<" pour la classe Disk
 *
 * \param out objet permettant d'afficher dans la console
 * \param d disque que l'on souhaite afficher
 * \return Chaine de caractère avec les infos du disque sur la console.
 */
std::ostream& operator<<(std::ostream& out, const Disk & d) {
    if (d.diameter!=0) {
        out<< "Disque (diametre = " <<d.diameter<<")"<<std::endl;
    }
    return out;
};