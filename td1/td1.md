## TD1 
# Hello World
1°/ En testant le programme de 1 à 16 on constate que les tâches se font dans un ordre aléatoire. 
2°/ Une sortie en fichier est plus clair qu'une sortie en terminal, parce que l'on ne perd pas les données et que cela arrive dans l'ordre ! 

# Envoie bloquant et non bloquant

# Circulation d'un jeton dans un anneau 
1°/ Si les proccesseurs s'affichent dans l'ordre c'est parce que les processeurs s'appelent l'un après l'autre. Ils doivent attendre d'avoir ce que leurs envoie le processeur d'avant pour pouvoir faire leur tâche ! C'est pourquoi le processeur 0 arrive en dernier : il doit avoir la réponse du dernier processeur pour afficher son résultat! 
2°/ Les tâches se font dans le désordre. En effet les processeurs n'ont plus à attendre de recevoir qqch de du processur n-1 (et donc qu'il exécute sa tâche) avant d'envoyer un truc ! Une fois que les processeurs aient envoyé leur jeton, le processeur n+1 peut le recevoir! 

# Calcul de pi par lancer de fléchettes
Pour 1000000 points, nous avons pour: 
- Bloquant : 10 secondes 
- Non Bloquant : 1 seconde ou moins. 
Sans séparer les tâches pour 100000000: 12 secondes en envoie non bloquant : 4 sec 
 

