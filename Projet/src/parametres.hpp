#ifndef _PARAMETRES_HPP_
#define _PARAMETRES_HPP_
#include <random>

/***************************************************************************************************
 * @brief      Paramètres pour les différentes colonies                                            *
 **************************************************************************************************/
struct parametres
{
    double apparition_civ; // Pourcentage de chance qu'apparaisse une civilisation techno sur une planète
    double expansion; // Pourcentage de chance qu'une planète décide d'aller habiter d'autres planètes
                      // Si le tirage au hasard donne un % inférieur à la moitié d'expansion, la planète
                      // fait une politique d'expansion à outrance et colonise tous les systèmes planétaires
                      // voisins.
    double disparition; // Pourcentage de chance qu'une planète ne possède plus de race intelligente
    double inhabitable; // Pourcentage de chance qu'une planète ne devienne plus habitable pour la vie
};

enum expansion
{
    pas_d_expansion = 0, expansion_unique, expansion_isotrope
};



expansion calcul_expansion(const parametres& c, std::uniform_real_distribution<double>& rd,
                           std::minstd_rand0& generator);
bool      calcul_depeuplement(const parametres& c, std::uniform_real_distribution<double>& rd,
                           std::minstd_rand0& generator);
bool      calcul_inhabitable(const parametres& c, std::uniform_real_distribution<double>& rd,
                           std::minstd_rand0& generator);

void mise_a_jour_omp(const parametres& p, int width, int height, const char* galaxie_previous, char* galaxie_next);
void mise_a_jour(const parametres& params, int width, int height, const char* galaxie_previous, char* galaxie_next);
void 
mise_a_jour_mpi(const parametres& params, int width, int height, const char* galaxie_previous, char* galaxie_next);
#endif