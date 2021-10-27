# Projet Poker

## Installation
Il faut spécifier `--recursive` au `git clone` pour installer le submodule de GoogleTests :

- `git clone https://github.com/codewithjordy/projet---pocker-Salvas21.git --recursive`

Si il y a une erreur à propos du submodule lors du `git clone`, essayer de faire :
- `git submodule update --remote`

Si ça marche toujours pas :
- Essayer d'installer la librairie de GoogleTests manuellement `https://github.com/google/googletest.git`
- Sinon me demander je peux prendre le temps de fix le submodule de mon bord et le push ou bien sinon t'envoyer ma copie des fichiers

## Configuration
- Tout développement, builds et tests ont été faits à l'aide de CLion, donc je recommande fortement d'utiliser mon programme à l'aide de ce dernier
- Dans le cas que les "Run/Debug Configurations" ne fonctionnent pas, s'assurer d'avoir un CMake Profile dans les Préférences de CLion ("Preferences" > "Build, Execution, Deployment" > "CMake")

## Patrons de conceptions

### Factory
J'utilise la __Factory__ pour pouvoir décider lors de l'exécution le style de poker à instancier. Je passe en parametre le choix du style de poker de l'utilisateur et la __Factory__ retourne un objet enfant de PokerStyle.

### Template Method
J'utilise une __Template Method__ pour ma fonction `play()` de mes PokerStyles, la fonction est definie `pure virtual` (abstract) par le parent PokerStyle et les enfants doivent absolument la redéfinir selon leurs besoins. 

### Builder
J'utilise un genre de __Builder__ pour la création de ma __Chain of Responsibility__. Lorsque j'ajoute un prochain Handler à ma chaine, la fonction retourne ce dernier pour que je puisse donc continuer à ajouter directement mes Handlers un à la suite des autres : `handler->setNext(lou)->setNext(lucy)...`. Je ne pense pas que cette utilisation se justifie comme étant un __Builder__ puisque ce n'est pas le même objet qui appelle toujours les fonctions, mais si l'on se dit que la chaine est un plus gros objet que simplement des Handlers un à la suite de l'autre, le patron du __Builder__ peut faire du sens 🤷‍♂️.

### Facade
J'ai aussi une __Facade__ pour la création de ma __Chain of Responsibility__, la __Facade__ a une fonction publique qui s'assure de créer les Handlers, d'ajouter les Handlers un à la suite de l'autre, de "handle", et de supprimer les Handlers. Ce patron permet donc de simplifier énormément l'utilisation de ma __Chaine de responsabilité__.

J'utilise aussi une petite __Facade__ au niveau de mes Consoles pour print les informations de fin de jeu tel que les cartes communautaires, les joueurs, leurs cartes initiales, leur rang de main, les cartes de leur main, ainsi que le ou les gagnants.

### Chain of Responsibility
Finalement, j'utilise une __CoR__ pour faire la vérification des mains des joueurs. Je lui passe en paramètre les cartes du joueur et les cartes communautaires triés en ordre de numéro. Ensuite la __CoR__ va retourner une Hand avec un HandRank (Ex: Pair, Straight, etc.) ainsi que les 5 cartes faisant partie de la main. J'assigne ensuite la valeur de retour à la main du joueur.

## Conclusion
### L'utilisation de la CoR
Je trouve que l'utilisation de la Chain of Responsibility était énormément pertinente. Cela permet une façon efficace de vérifier les cartes et de quitter dès qu'elles correspondes à une main. Cela fait donc en sorte que l'on va pas "overwrite" la main d'un joueur avec une main plus faible.
