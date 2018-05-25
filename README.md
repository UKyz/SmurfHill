# Welcome in a game Qt in MVC

<p align="center">
  <img src="http://victor-fauquembergue.fr/imagesGit/smurf1">
</p>


This game has been developed for a school project. This is a one player game based on a survival game. You have a Smurf community who has to survive against the enemies and find resources to feed and treat each Smurf.

The game is also available in French.
Feel free to contribute or discuss the game.

## Contents
  * [Install & Play][Installation]
  * [Requirements][Requirements]
  * [Gameplay][Gameplay]
    * [Village][Village]
    * [Forests][Forests]
    * [Characters][Persos]
      * [NicePerso][NicePerso]
      * [MadPerso][MadPerso]
      * [NonPlayerPerso][NonPlayerPerso]
    * [Screenshots][Screenshots]
  * [Team][Team]

## Install & Play

* Open QtCreator
* New Project
* In "Import Project" choose Git clone
* In Repository add : ```https://github.com/UKyz/SmurfHill.git```
* Continue
* Run

## Requirements 

* Qt (>= 5.2) [(install link)][Qt]
* Qt multimedia

## Gameplay

The aim of the game is to survive in a world full of dangerous enemies. <br />
At the very beginning of the game, you are near the Smurf Village. The Smurf village is composed of Smurfs' houses and some characters. The main characters of the village are Papa Smurf, Smurfette, Farmer Smurf, Baker Smurf, Hefty Smurf, Doctor Smurf and Brainy Smurf. These characters are called the NonPlayerPerso, they help you as much as they can. <br />
Around the village are some Smurfs, they are named NicePerso. These Smurfs can move on the map to find resources for the village. But be careful, enemies are hidden in the forests to prevent you from catching some wheat, berries and acorn.

### Village

The village is placed in the middle of the map. This area is a safe and pleasant place to live for the Smurfs. In it you'll find the Smurf's houses and some characters: <br />
* Papa Smurf is the leader of the village. His role is to give you some advice about the game.
* Smurfette is the narrator.
* Musician Smurf is a great musician playing the Smurf generic.
* Brainy Smurf is annoying but he will inform you about the level of Farmer, Baker and Hefty. Beside this, he gives you each one's features.
* Farmer Smurf, Baker Smurf and Hefty Smurf are called NonPlayerPerso.

### Forests

The Smurf village is hidden in the forest so that Gargamel can't find the Smurfs. All around the village, you'll find forests in which are hidden resources and enemies. <br />
There are 4 different types of resources: <br />
*	Wheat which is used to make bread.
*	Berries useful to feed and treat injured Smurfs.
*	Acorns also used as a treatment.
*	Sarsaparillas considered as a money.

### Characters

#### NicePerso

The Smurf community is composed of NicePerso. These characters will move on the map to the point you clicked. If they go through a resource, the Smurf will pick it up and add it to the inventory of the village. <br />
Going into a forest is dangerous because of the MadPerso. Fighting a MadPerso will give you 100 points for the score but the Smurfs will lose living points. You will need to feed them thanks to Doctor Smurf.

#### MadPerso

As in every world, enemies are there to make the game more difficult. The enemies are placed at every strategic point such as on a crossroad or at each forest entrance. <br />
Each enemy has living and damage points. Each fight between NicePerso and MadPerso will cause point loose. As soon as the NicePerso is done fighting and wins, he can keep going but a new MadPerso will reappear after 30 seconds.

#### NonPlayerPerso

Farmer Smurf, Baker Smurf, Hefty Smurf and Doctor Smurf are called the NonPlayerPerso. Each one has specific skills: <br />
*	Farmer Smurf has fields to harvest. He will give you some wheat.
*	Baker Smurf is the baker of the village. Thanks to the wheat you collected or the one Farmer harvested, Baker can cook bread for the community.
*	Hefty Smurf is the strongest Smurf. He is the best one to train the NicePerso to become stronger. Thanks to him, to can get new NicePerso to send them explore the forests and fight against the enemies. Improving Hefty will allow the new NicePerso to have more living and damage points.
*	Doctor Smurf is the doctor. Using food will treat the injure NicePerso.
 
### Screenshots

<p align="center">
  <img width="356" height="200" src="http://victor-fauquembergue.fr/imagesGit/smurf2">
  <img width="356" height="200" src="http://victor-fauquembergue.fr/imagesGit/smurf3">
  <br />
  <img width="356" height="200" src="http://victor-fauquembergue.fr/imagesGit/smurf4">
  <img width="356" height="200" src="http://victor-fauquembergue.fr/imagesGit/smurf5">
  <br />
  <img width="356" height="200" src="http://victor-fauquembergue.fr/imagesGit/smurf6">
  <img width="356" height="200" src="http://victor-fauquembergue.fr/imagesGit/smurf7">
  <br />
  <img width="356" height="200" src="http://victor-fauquembergue.fr/imagesGit/smurf8">
  <img width="356" height="200" src="http://victor-fauquembergue.fr/imagesGit/smurf9">
 </p>

## Credits
  * Couton Alexia (Save, Decor, Translations)
  * Fauquembergue Victor (MVC, Perso, GameLoop, Resource)

[Installation]: https://github.com/UKyz/SmurfHill/blob/master/README.md#install--play
[Qt]: https://www.qt.io/download
[Requirements]: https://github.com/UKyz/SmurfHill/blob/master/README.md#requirements
[Gameplay]: https://github.com/UKyz/SmurfHill/blob/master/README.md#gameplay
[Screenshots]: https://github.com/UKyz/SmurfHill/blob/master/README.md#screenshots
[Village]: https://github.com/UKyz/SmurfHill/blob/master/README.md#village
[Forests]: https://github.com/UKyz/SmurfHill/blob/master/README.md#forests
[Persos]: https://github.com/UKyz/SmurfHill/blob/master/README.md#characters
[NicePerso]: https://github.com/UKyz/SmurfHill/blob/master/README.md#niceperso
[MadPerso]: https://github.com/UKyz/SmurfHill/blob/master/README.md#madperso
[NonPlayerPerso]: https://github.com/UKyz/SmurfHill/blob/master/README.md#nonplayerperso
[Team]: https://github.com/UKyz/SmurfHill/blob/master/README.md#team-
