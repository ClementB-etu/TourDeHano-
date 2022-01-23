/**
 * \file Tower.cpp
 * \brief Définit les fonctions de la classe Tower qui seront utilisées pour la résolution du problème.
 * \author Clément BELLEIL
 * \version 1
 * \date 23 Janvier 2022
 *
 * Définition des fonctions utiles à l'utilisation des objets de la classe Tower
 *
 */

#include "Tower.hpp"

/**
 * \fn Tower()
 * \brief Constructeur par défaut de Tower
 *
 * \return Instance nouvelle d'un objet Tower
 */
Tower::Tower() {
    std::vector<Disk> VectDisk;
    this->myDisks = VectDisk;
}

/**
 * \fn Tower(std::string name)
 * \brief Constructeur de Tower avec le nom de la tour
 *
 * \param name Nom de la tour
 * \return Instance nouvelle d'un objet Tower
 */
Tower::Tower(std::string name) {
    std::vector<Disk> VectDisk;
    this->myDisks = VectDisk;
    this->name = name; 
}

/**
 * \fn getName()
 * \brief retourne le nom de l'objet Tower
 *
 * \return nom de la tour
 */
std::string Tower::getName(){
    return this->name;
}

/**
 * \fn pushDisk(d)
 * \brief ajoute le disque passé en argument sur la tour
 *
 * \param d disque que l'on souhaite placer sur le haut de la tour
 * \return void
 */
void Tower::pushDisk(Disk d) {
    this->myDisks.push_back(d);
    std::cout<<"  -> Déplacement FAIT"<<std::endl;
}

/**
 * \fn isEmpty(d)
 * \brief retourne l'information si la tour est vide ou non
 *
 * \return true si la tour est vide, false sinon
 */
bool Tower::isEmpty(){
    return this->myDisks.empty();
}

/**
 * \fn isPossible(d)
 * \brief renseigne sur la possibilité de bouger d sur la tour (en regardant si la tour est vide, et sinon, si le diamètre du disque en haut de la tour est supérieur ou non à celui de d)
 *
 * \return true si la déplacement est possible, false sinon
 */
bool Tower::isPossible(Disk d) {
    if (this->isEmpty()) {
        return true;
    } else {
        return (this->popDisk().getDiameter()>d.getDiameter());
    }
}

/**
 * \fn popDisk()
 * \brief retourne le disque en haut de la pile d'une pile non vide, ou un disque de diamètre 0 si elle est vide (ainsi, le déplacement d'un disque sera toujours possible car les disques ont un diamètre strictement supérieur à 0)
 * 
 * \return le disque du haut de la tour si elle est non vide, et un disque de diamètre 0 si elle l'est
 */
Disk Tower::popDisk() {
    if (this->isEmpty()) {
        return Disk(0);
    } else {
        return this->myDisks[this->myDisks.size()-1];
    }   
}

/**
 * \fn removeDisk()
 * \brief supprime la référence à l'objet en haut de la tour dans le vecteur myDisks (car celui-ci s'est déplacé)
 * 
 * \return void
 */
void Tower::removeDisk() {
    if (!this->isEmpty()) {
        this->myDisks.erase(this->myDisks.begin()+this->myDisks.size()-1);
    }
}

/**
 * \fn containsFirst(Disk d)
 * \brief renseigne sur le fait que d soit en haut de la tour ou non
 * 
 * \param d disque considéré
 * \return true si le disque est en haut de la tour, false sinon
 */
bool Tower::containsFirst(Disk d) {
    return (this->popDisk().getDiameter()==d.getDiameter());
}

/**
 * \fn contains(Disk d)
 * \brief renseigne sur le fait que d soit sur la tour ou non, pour afficher pourquoi un mouvement n'est pas possible (déplacement impossible car le disque n'est pas premier de la tour)
 * 
 * \param d disque considéré
 * \return true si le disque est sur la tour, false sinon
 */
bool Tower::contains(Disk d) {
    for (long unsigned int i=0;i<this->myDisks.size();i++) {
        if (this->myDisks.at(i).getDiameter()==d.getDiameter()) {
            return true;
        }
    }
    return false;
}

/**
 * \fn std::ostream& operator<<(std::ostream& out, const Tower & t)
 * \brief redéfinit l'opérateur "<<" pour la classe Tower
 * 
 * \param out objet permettant d'afficher dans la console
 * \param t tour que l'on souhaite afficher
 * \return Chaine de caractère avec les infos de la tour sur la console.
 */
std::ostream& operator<<(std::ostream& out, const Tower & t) {
    out<< "Tour " <<t.name<<" :"<<std::endl;
    for (long unsigned int i=0;i<t.myDisks.size();i++) {
        out<< t.myDisks.at(i) <<std::endl;
    }
    return out;
}
