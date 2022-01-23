/**
 * \file Game.cpp
 * \brief Définit les fonctions de la classe Game qui seront utilisées pour la résolution du problème.
 * \author Clément BELLEIL
 * \version 1
 * \date 23 Janvier 2022
 *
 * Définition des fonctions utiles à l'utilisation des objets de la classe Game
 *
 */
#include "Game.hpp"

/**
 * \fn Game()
 * \brief Constructeur par défaut de Game
 *
 * \return Instance nouvelle d'un objet Game
 */
Game::Game(){
    std::vector<Tower> Towers;
    this->myTowers= Towers;
}

/**
 * \fn Game(int nbdisk)
 * \brief Constructeur de Game avec le nombre de disque la composant
 *
 * \param nbdisk Nombre de disque dans la partie
 * \return Instance nouvelle d'un objet Game
 */
Game::Game(int nbdisk){
    std::vector<Tower> Towers;
    this->myTowers= Towers;
    this->nbdisk = nbdisk;
}

/**
 * \fn solve()
 * \brief résout la partie en appelant les différentes méthodes en fonction du nombre de disque
 *
 * \return void
 */
const void Game::solve() {
    std::cout<<"Début de la résolution"<<std::endl;
    if (this->nbdisk%2==0) { //Réslution avec nombre de disque pair
        this->solvePair();
    } else { //Résolution avec nombre de disque impair
        this->solveImpair();
    }
    std::cout<<"Résolution terminée !"<<std::endl;
}

/**
 * \fn solvePair()
 * \brief résout la partie si le nombre de disque est pair
 * 
 * On déplace toujours le plus petit disque vers la droite PUIS le moyen disque vers la droite et ainsi de suite
 * 1 appel de solvePair tente de bouger 1 fois tous les disques
 * nbcoupmini est le nombre de coup minimal pour la résolution du problème, en fonction du nombre de disques
 * 
 * \return void
 */
void Game::solvePair() {
    int nbcoupmini = pow(2,this->nbdisk)-1;
    int intcompt = 0;
    while (intcompt<nbcoupmini) {
        for (int i =0;i<this->nbdisk;i++) {
            intcompt += this->towerDestPair(this->allDisks.at(i));
        }
    }
}

/**
 * \fn solvePair()
 * \brief résout la partie si le nombre de disque est impair
 *
 * On déplace toujours le plus petit disque vers la gauche PUIS le moyen disque vers la gauche et ainsi de suite
 * 1 appel de solveImpair tente de bouger 1 fois tous les disques
 * nbcoupmini est le nombre de coup minimal pour la résolution du problème, en fonction du nombre de disques
 * 
 * \return void
 */
void Game::solveImpair() {
    int nbcoupmini = pow(2,this->nbdisk)-1;
    int intcompt = 0;
    while (intcompt<nbcoupmini) {
        for (int i =0;i<this->nbdisk;i++) {
            intcompt += this->towerDestImpair(this->allDisks.at(i));
        }
    }

}

/**
 * \fn getTower(int i)
 * \brief renvoie l'objet Tower voulu en fonction de son index dans myTowers
 *
 * \param i index de la tour que l'on souhaite récupérer
 * \return pointeur vers la tour que l'on souhaite récupérer
 */
Tower* Game::getTower(int i) {
    return &this->myTowers[i];
}

/**
 * \fn setTower(Tower t)
 * \brief utilisée pour construire le vecteur myTowers
 *
 * \param t objet Tower à ajouter à la partie
 * \return void
 */
void Game::setTower(Tower t) {
    this->myTowers.push_back(t);
}

/**
 * \fn towerDestPair(Disk d)
 * \brief cherche la tour suivante pour le disque d, en fonction de sa position sur sa tour, de son diamètre et du nombre de disque, et le déplace sur sa nouvelle tour
 *
 * \param d disque que l'on souhaite tenter de bouger
 * \return 1 si d à été bougé, 0 sinon (sert pour la condition d'arrêt à la partie avec le nombre de coup minimal)
 */
int Game::towerDestPair(Disk d) {
    long unsigned int indtower = 0;
    std::cout<<"--- Début tentative de mouvement ---"<<std::endl;
    for (long unsigned int i=0;i<this->myTowers.size();i++) {
        if ((!this->myTowers.at(i).isEmpty())&&(this->myTowers.at(i).containsFirst(d))) { //Le disque cible est bien en haut de la tour
            indtower = i;
        } else if (this->myTowers.at(i).contains(d)) {
            std::cout<<d<<" non déplaçable car non premier"<<std::endl;
            std::cout<<"--- Fin tentative de mouvement ---"<<std::endl;
            return 0;
        }
    }
    if(this->myTowers.at(indtower).containsFirst(d)) {
        Tower towersuiv = this->myTowers.at((indtower+1)%(this->myTowers.size()));
        Tower towersuiv2 = this->myTowers.at((indtower+2)%(this->myTowers.size()));
        if(towersuiv.isPossible(d)) {
            std::cout<<d<<" va sur la tour "<<this->myTowers.at((indtower+1)%(this->myTowers.size())).getName()<<std::endl;
            this->myTowers.at((indtower+1)%(this->myTowers.size())).pushDisk(d);
            this->myTowers.at(indtower).removeDisk();
            std::cout<<"--- Fin tentative de mouvement ---"<<std::endl;
            return 1;
        } else if (towersuiv2.isPossible(d)){
            std::cout<<d<<" va sur la tour "<<this->myTowers.at((indtower+2)%(this->myTowers.size())).getName()<<std::endl;
            this->myTowers.at((indtower+2)%(this->myTowers.size())).pushDisk(d);
            this->myTowers.at(indtower).removeDisk();
            std::cout<<"--- Fin tentative de mouvement ---"<<std::endl;
            return 1;
        } else {
            std::cout<<d<<" non déplaçable mais premier de sa tour"<<std::endl;
            std::cout<<"--- Fin tentative de mouvement ---"<<std::endl;
            return 0;
        }
    }
    std::cout<<"--- Fin tentative de mouvement ---"<<std::endl;
    return 0;
}

/**
 * \fn towerDestImpair(Disk d)
 * \brief cherche la tour suivante pour le disque d, en fonction de sa position sur sa tour, de son diamètre et du nombre de disque, et le déplace sur sa nouvelle tour
 *
 * \param d disque que l'on souhaite tenter de bouger
 * \return 1 si d à été bougé, 0 sinon (sert pour la condition d'arrêt à la partie avec le nombre de coup minimal)
 */
int Game::towerDestImpair(Disk d) {
    long unsigned int indtower = 0;
    for (long unsigned int i=0;i<this->myTowers.size();i++) {
        if ((!this->myTowers.at(i).isEmpty())&&(this->myTowers.at(i).containsFirst(d))) {           //Le disque cible est bien en haut de la tour
            indtower = i;
        } else if (this->myTowers.at(i).contains(d)) {
            std::cout<<d<<"Disque non déplaçable car non premier"<<std::endl;
            return 0;
        }
    }
    if(this->myTowers.at(indtower).containsFirst(d)) {
        Tower towersuiv = this->myTowers.at((indtower+2)%(this->myTowers.size()));
        Tower towersuiv2 = this->myTowers.at((indtower+1)%(this->myTowers.size()));
        if(towersuiv.isPossible(d)) {
            std::cout<<" i : "<<indtower<<" tour suivante : "<<std::endl;
            std::cout<<this->myTowers.at((indtower+2)%(this->myTowers.size()))<<std::endl;
            this->myTowers.at((indtower+2)%(this->myTowers.size())).pushDisk(d);
            this->myTowers.at(indtower).removeDisk();
            return 1;
        } else if (towersuiv2.isPossible(d)){
            std::cout<<" i : "<<indtower<<" tour suivante : "<<std::endl;
            std::cout<<this->myTowers.at((indtower+1)%(this->myTowers.size()))<<std::endl;
            this->myTowers.at((indtower+1)%(this->myTowers.size())).pushDisk(d);
            this->myTowers.at(indtower).removeDisk();
            return 1;
        } else {
            std::cout<<d<<"Disque non déplaçable mais premier"<<std::endl;
            return 0;
        }
    }
    return 0;
}

/**
 * \fn std::ostream& operator<<(std::ostream& out, const Game & g)
 * \brief redéfinit l'opérateur "<<" pour la classe Game
 * 
 * \param out objet permettant d'afficher dans la console
 * \param g partie que l'on souhaite afficher
 * \return Chaine de caractère avec les infos de la tour sur la console.
 */
std::ostream& operator<<(std::ostream& out, const Game & g) {
    out<< "Partie :"<<std::endl;
    for (long unsigned int i=0;i<g.myTowers.size();i++) {
        out<< g.myTowers.at(i) <<std::endl;
    }
    return out;
}

/**
 * \fn ~Game()
 * \brief déstructeur d'un objet Game
 */
Game::~Game(){};

/**
 * \fn main()
 * \brief fonction qui construit les objets nécessaires à la partie, et la résout
 * 
 * Décommenter les lignes considérées pour tester la résolution avec un nombre de disque impair
 * 
 * \return 0 si tout s'est bien déroulé
 */
int main() {

    Game *game = new Game(4);
    //Game *game = new Game(5);

    Disk *disk1 = new Disk(1);
    Disk *disk2 = new Disk(2);
    Disk *disk3 = new Disk(3);
    Disk *disk4 = new Disk(4);
    //Disk *disk5 = new Disk(5);

    Tower *tower1 = new Tower("départ");
    Tower *tower2 = new Tower("intermédiaire");
    Tower *tower3 = new Tower("arrivée");

    game->setTower(*tower1);
    game->setTower(*tower2);
    game->setTower(*tower3);

    //game->getTower(0)->pushDisk(*disk5);
    game->getTower(0)->pushDisk(*disk4);
    game->getTower(0)->pushDisk(*disk3);
    game->getTower(0)->pushDisk(*disk2);
    game->getTower(0)->pushDisk(*disk1);

    game->allDisks.push_back(*disk1);
    game->allDisks.push_back(*disk2);
    game->allDisks.push_back(*disk3);
    game->allDisks.push_back(*disk4);
    //game->allDisks.push_back(*disk5);
    
    std::cout<<" -- AVANT RESOLUTION -- "<<*game<<std::endl;
    game->solve();
    std::cout<<" -- APRES RESOLUTION -- "<<*game<<std::endl;
    game->~Game();
    return 0;
}