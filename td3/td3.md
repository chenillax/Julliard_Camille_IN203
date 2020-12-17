 TP2 de NOM Prénom

`pandoc -s --toc tp2.md --css=./github-pandoc.css -o tp2.html`





## lscpu

```
coller ici le résultats de lscpu. 
```

*Des infos utiles s'y trouvent : nb core, taille de cache*



## Produit scalaire 

*Expliquer les paramètres, les fichiers, l'optimisation de compil, NbSamples, ...*

OMP_NUM    | samples=1024 | 
-----------|--------------|----------
séquentiel |   | 
1          |   | 
2          |   | 
3          |   | 
4          |   | 
8          |   | 


*Discuter sur ce qu'on observe, la logique qui s'y cache.*




## Produit matrice-matrice



### Permutation des boucles

*Expliquer comment est compilé le code (ligne de make ou de gcc) : on aura besoin de savoir l'optim, les paramètres, etc. Par exemple :*

`make TestProduct.exe && ./TestProduct.exe 1024`


  ordre           | time    | MFlops  | MFlops(n=2048) 
------------------|---------|---------|----------------
i,j,k (origine)   | 53.478  | 40.1564 |                
j,i,k             | 68.0581 | 31.5537 |    
i,k,j             | 85.6492 | 25.073  |    
k,i,j             | 82.6433 | 25.985  |    
j,k,i             | 24.4915 | 87.6827 |    
k,j,i             | 23.4612 | 91.5335 |    


*Discussion des résultats*



### OMP sur la meilleure boucle 

`make TestProduct.exe && OMP_NUM_THREADS=8 ./TestProduct.exe 1024`

  OMP_NUM         | MFlops  | MFlops(n=2048) | MFlops(n=512)  | MFlops(n=4096)
------------------|---------|----------------|----------------|---------------
1                 | 89.2435 | | 89.574  |
2                 | 87.7449 | | 86.3669 |
3                 | 87.7824 | | 80.4652 |
4                 | 91.1995 | | 75.0204 |
5                 | 75.8523 | | 81.2683 |
6                 | 79.6099 | | 82.1961 |
7                 | 78.5557 | | 87.3277 |
8                 | 85.6024 | | 84.3693 |




### Produit par blocs

`make TestProduct.exe && ./TestProduct.exe 1024`

  szBlock         | MFlops  | MFlops(n=2048) | MFlops(n=512)  | MFlops(n=4096)
------------------|---------|----------------|----------------|---------------
origine (=max)    |  |
32                |  |
64                |  |
128               |  |
256               |  |
512               |  | 
1024              |  |




### Bloc + OMP



  szBlock      | OMP_NUM | MFlops  | MFlops(n=2048) | MFlops(n=512)  | MFlops(n=4096)
---------------|---------|---------|------------------------------------------------
A.nbCols       |  1      |         | 
512            |  8      |         | 







# Tips 

```
	env 
	OMP_NUM_THREADS=4 ./dot_product.exe
```

```
    $ for i in $(seq 1 4); do elap=$(OMP_NUM_THREADS=$i ./TestProductOmp.exe|grep "Temps CPU"|cut -d " " -f 7); echo -e "$i\t$elap"; done > timers.out
```