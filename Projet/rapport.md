# RAPPORT PROJET IN203 CAMILLE JULLIARD

## Parallélisation de boucle en mémoire partagée

Lorsqu'on parallélise la fonction `mise_a_jour_omp` de parametres.cpp, il peut y avoir un data race. En effet, 2 threads peuvent écrire en même temps dans `galaxie_next`, lorsque l'un va coloniser les planètes autours et l'autre va changer l'état de la planère sur laquelle il travaille. En pratique, ce data race n'arrive pas car ces deux évènements n'arrivent jamais en même temps. En effet, pour que cela arrive il faut que les deux threads travaillent en même temps sur 2 planètes adjacentes. Cela revient à ce qu'il y ait autant de thread que de lignes. Ce qui n'est pas le cas en pratique. 
Néanmoins pour s'assurer qu'il n'y a pas de data race, nous pouvons mettre des instructions `#pragma omp atomic` avant les écritures dans `galaxie_next` problématiques,  pour s'assurer qu'il n'y ait aucun problème.

|         | Calcul (ms) | Affichage (ms) |
| :-------| ------------| --------------:| 
|Sans OPM |  16,018     |    1,1         |
|Avec OMP |  11,234    |    1,4         | 

Ces résultats ont été choisis pour un temps compris entre 450 et 475 k années. 

Avoir ajouté les instructions `#pragma omp atomic` ne rajoutent pas plus de temps lors de l'exécution du calcul.

*Calcul du Speed Up* 

|         | Calcul | Affichage | Total |
| :-------| ------------| ---|-----------:|
| Speedup | 1,42   |  0,7      | 1,35  |

## Recouvrement calcul / affichage en mémoire partagée 

Ici, il a fallu changer la fonction `main` dans le fichier colonisation.cpp afin de mettre un côté une tache qui affiche et l'autre qui fait la mise à jour. Ici la fonction `mise_a_jour` est la fonction de base, non parralélisé. 

Nous avons alors : 
|                     | Calcul (ms) | Affichage (ms) | Temps Moyen |
| :-------| ------------| --------------| ---------:|
|Sans //              |  16,056     | 1,008          | 16,993      |
|Avec OMP             | 15,448      | 1,534          | 16,531      |

Ces résultats ont été choisis pour un temps compris entre 370 et 375 k années. 

J'ai choisi ici de comparer les temps moyens par boucle, car sur une boucle donnée, cela été trop proche. 

*Calcul du speedup :* 

|         | Calcul | Affichage | Temps Moyen |
| :-------| ------------| --------------|-----:|
| Speedup | 1,03   |  0,65     |  1.02       |

Nous pouvons alors voir, que la parralélisation en OpenMP de la fonction principale n'ajoute pas grand chose. Cela semble étrange, mais je n'ai plus le temps d'étudier la question. 


## Parallélisation en mémoire distribuée

Ici, il a fallu changer la fonction `main` dans le fichier colonisation.cpp ainsi que la fonction `mise_a_jour` dans parametres.cpp, pour l'adapter à la prédiction de la galaxie suivante sur une tranche avec des cellules fantômes. 

Nous avons alors : 
|                     | Calcul (ms) | Affichage (ms) | 
| :-------| ------------| --------------:|
|Sans //              |  22,195     | 2,472          |
|Avec MPI, 3 processus| 11,803      | 1,839          | 
|Avec MPI, 5 processus| 12,786      | 2,215          |

Ces résultats ont été choisis pour un temps compris entre 550 et 575 k années. 
Nous remarquons alors qu'avoir plus de processus n'augementent pas le temps de calcul, voir même qu'il le ralentit. Cela est surement du à la capacité de mon ordinateur : n'ayant que 2 coeurs, je ne peux avoir que 4 processus efficaces. 

*Calcul du speedup avec 3 processeurs : *

|         | Calcul | Affichage | Total |
| :-------| ------------| --------|------:|
| Speedup | 1,88   |  1,34     | 1,8  |

Le speedup en calcul est le plus élevé que j'ai calculé. Cette méthode semble être la plus efficace ! 