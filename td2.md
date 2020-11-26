## TD 2 

# Question de cours 

Premier scénario où il n'y pas d'interblocage :
    0 envoie message au 2 
    0 recoit message du 2 
    1 envoie message au 2 
    2 reçoit message du 0 
    2 envoit message au 0 
    2 reçoi message du 1

Deuxième scénario avec interblocage :
    0 envoie message au 2 
    0 recoit message du 2 
    1 envoie message au 2 
    2 reçoit message du 1 
    2 envoit message au 0 
    2 reçoi message du 0

La probabilité d'avoir un interblocage est de 1/2.

# Question de cours 2 

On a, d'après la loi d'Amdhal, S(n)=n/(1+(n-1)f) = n/(f*(n-1)) = 1/f = 10 ! 

En prenant 500 Noeud de calculs nous trouvons une accéleartion égale au centieme près à l'acélration maximale trouvée.

Avec une accélaration maximale de 4, on a donc une portion de temps de code en séquentiel de 0.25. 
Donc après tout calculs fait, la loi de Gustafon nous permet de trouver une accélaration de 7.75.

# Ensemble de Mandelbrot 







