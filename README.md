# bcat 
bcat is a braille cat for linux or mac os.
bcat allows to read a filetext on the braille display.
example :
bcat foobar.txt
**********
bcat create a virtual hlaille display and syncronize with your personal braille display.
## WARNING
bcat uses brlapi (brltty) for the braille support.
please install this package.
For example on debian/ubuntu:
sudo apt-get update && apt-get install brltty brlapi-dev
### Credits
Dave Mielke for brltty.

#### bugs known
* crash with special char.
* load faille if a file is too big.
##### next stape -->
* init automaticaly for all keyboard.
* adding pdf file support.
* create a gbcat for all users.

READ the man for all informations
