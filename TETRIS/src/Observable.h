 #ifndef __OBSERVABLE__H__
#define __OBSERVABLE__H__


#include <set>
#include <string>




namespace model {
class Game;
}
class Observer;
/*!
 * \brief Classe de base de tout observable (ou "sujet d'observation").
 *
 * Classe dont dérive toute source d'événement (ou "sujet d'observation")
 * du modèle de conception "Observateur / Observable".
 *
 * \sa Observer.
 */
class Observable
{
public:

    /*!
     * \brief Destructeur virtuel par défaut car utilisation polymorphique.
     */
    virtual ~Observable() = default;

    /*!
     * \brief Constructeur par recopie par défaut.
     *
     * Le destructeur virtuel par défaut a des effets en cascade.
     *
     * \see http://stackoverflow.com/q/33957037
     * \see http://scottmeyers.blogspot.de/2014/03/a-concern-about-rule-of-zero.html
     */
    Observable(const Observable &) = default;

    /*!
     * \brief Constructeur par déplacement par défaut.
     *
     * Le destructeur virtuel par défaut a des effets en cascade.
     *
     * \see http://stackoverflow.com/q/33957037
     * \see http://scottmeyers.blogspot.de/2014/03/a-concern-about-rule-of-zero.html
     */
    Observable(Observable &&) = default;

    /*!
     * \brief Opérateur d'assignation par recopie par défaut.
     *
     * Le destructeur virtuel par défaut a des effets en cascade.
     *
     * \see http://stackoverflow.com/q/33957037
     * \see http://scottmeyers.blogspot.de/2014/03/a-concern-about-rule-of-zero.html
     */
    Observable & operator=(const Observable &) = default;

    /*!
     * \brief Opérateur d'assignation par déplacement par défaut.
     *
     * Le destructeur virtuel par défaut a des effets en cascade.
     *
     * \see http://stackoverflow.com/q/33957037
     * \see http://scottmeyers.blogspot.de/2014/03/a-concern-about-rule-of-zero.html
     */
    Observable & operator=(Observable &&) = default;

    /*!
     * \brief Méthode pour l'ajout d'un observateur au carnet d'adresse
     * des observateurs enregistés de l'observable.
     *
     * \param observer un pointeur vers le candidat observateur.
     */
    virtual void registerObserver(Observer * observer) final;

    /*!
     * \brief Méthode pour le retrait d'un observateur au carnet d'adresse
     * des observateurs enregistés de l'observable.
     *
     * \param observer l'adresse de l'observateur désintéressé.
     */
    virtual void unregisterObserver(Observer * observer) final;

protected:

    /*!
     * \brief Constructeur protégé pour éviter l'instanciation
     *        hors héritage.
     */
    Observable() = default;

    /*!
     * \brief Méthode qui se charge de prévenir les observateurs d'un
     * changement d'état de l'observable, en invoquant leur
     * méthode Observer::update().
     *
     * \sa Observer::update(const Observable *).
     */
    virtual void notifyObservers(model::Game *newState, std::string message) const;

protected:

    /*!
     * \brief L'ensemble d'observateurs enregistrés.
     */
    std::set<Observer *> observers_ { };
};



#endif
