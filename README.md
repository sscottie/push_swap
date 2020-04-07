# push_swap - sorting with two stackes

![Nyan Cat's reverse moon walk](https://github.com/sscottie/push_swap/blob/master/lib/visualisator/nyany.gif)

Main idea to sort the arrray of ints with minimal count of commands;

C, HTML, CSS, JavaScript used. 

## Usage

* git-clone
* terminal-> cd /cloned_repo/ -> make
* use it!

There are 3 binary:
* push_swap
* checker
* preparator (bonus)

use ./push_swap <int arguments to sort>
output: list of commands to sort the int progression;

use ./push_swap <int args> | ./checker <same int args> to check, is that sorted.
Output: if sorted returns OK, else KO;

## Scripts

Useful scripts attached: 
* randomizer.sh - generates random ints between n1 and n2, and writes it in env value $ARG.
  * to generate: write in terminal . ./randomizer.sh n1 n2
* visualizer.sh - generates random ints, uses push_swap binary, and sends output into JavaScript's code
  * to watch kitties: ./visualizer.sh n1 n2
  * also works with existing $ARG: ./visualizer

Enjoy Nyan Cat's fly!
