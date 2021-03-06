# 42-get_next_line
The aim of this project is to make you code a function 
that returns a lineending with a newline, 
read from a file descriptor.


## name functions

ft_name* -> gnl_*

## Error

you can't malloc a static variable

you need

```static char	buffer[BUFFER_SIZE];```


## Evaluation

### Norminette

Exécutez la norminette.
En cas d'erreur, l'évaluation s'arrête ici.
Vous pouvez continuer et discuter de l'implémentation du code,
mais cela ne sera pas noté.


### Gestion d'erreur

Effectuez au minimum les tests d'erreur suivants, afin de vérifier la gestion d'erreur
du programmme.
- Passez un fd arbitraire a la fonction get_next_line, sur lequel il
n'est pas possible de lire (par ex. 42) La fonction doit renvoyer NULL.
- Vérifiez les retours d'erreur de malloc, read et open.
Si la partie "gestion d'erreur" est fausse, merci de ne pas noter la partie suivante,
la correction s'arrête ici.
Vous pouvez continuer et discuter de l'implémentation du code,
mais cela ne sera pas noté.


### Tests

En temps qu'évaluateur, vous devez écrire ou apporter un main qui vérifie :
- La valeur de retour de la fonction get_next_line est NULL en cas d'erreur.
- Sinon, la fonction renvoie la ligne lue, toujours avec un \n à la fin.

Testez toutes les combinaisons des règles suivantes :
- Gros BUFFER_SIZE (> 1024)
- Petit BUFFER_SIZE (< 8, et 1)
- BUFFER_SIZE de la taille de la ligne à lire
- 1 de décalage (+/-) entre le BUFFER_SIZE et la ligne

- Lecture depuis stdin
- Lecture depuis un fichier

- (Multiple/Simple) ligne longue (2k+ caractères)
- (Multiple/Simple) ligne courte (<4 caractères, et 1)
- (Multiple/Simple) Ligne vide

Ces tests devraient vous permettre de vérifier la validité du projet de
l'étudiant.
En cas d'erreur, l'évaluation s'arrête ici.


### Bonus

Les bonus ne seront abordés que si votre partie obligatoire est excellente. 
Cela signifie que vous devez compléter la partie obligatoire, du début à la fin, 
que votre gestion d'erreur doit être parfaite, même dans des situations tordues. 
Si tous les points ne sont pas attribués pendant cette soutenance, 
aucun point ne sera comptabilisé dans les bonus.
Lecture sur multiple fd

Répetez les tests effectués au dessus, mais cette fois en lancant plusieurs instances de get_next_line,
chacune utilisant un file descriptor différent.
Assurez-vous que chaque get_next_line renvoie la bonne ligne.
Ajoutez un fd non-existant pour vérifier la gestion d'erreurs.

#### Single static variable

Lisez le code et vérifiez qu'il n'y a bien qu'une seule variable statique. Donnez les points si c'est le cas.

## Memory

```
    ┌────────────────┐
Buff│hey\nHow are y\0│
    └────────────────┘

    ┌─┐
Line│0│
    └─┘

    ┌─┐
Rest│0│
    └─┘

    ┌────────────────┐
Buff│hey\nHow are y\0│
    └────────────────┘

    ┌───────┐
Line│hey\n\0│
    └───────┘

         ┌───────────┐
Rest 0   │How are y\n│
         └───────────┘
```


![gif](https://github.com/theo-grivel/theo-grivel/blob/main/assets/homemade.gif)
![gif](https://github.com/theo-grivel/theo-grivel/blob/main/assets/homemade.gif)
![gif](https://github.com/theo-grivel/theo-grivel/blob/main/assets/homemade.gif)
![gif](https://github.com/theo-grivel/theo-grivel/blob/main/assets/homemade.gif)
![gif](https://github.com/theo-grivel/theo-grivel/blob/main/assets/homemade.gif)
