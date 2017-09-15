# bcat
bcat is a braille cat for linux or mac os.
bcat allows to read a filetext with a braille display
The filetext is directly put on the braille display.
example :
bcat foobar.txt
**********
bcat create a virtual hlaille display and syncronize with your personal braille display.
## WARNING
bcat uses brlapi (brltty) for the braille support.
please to install this package.
For example with debian/ubuntu:
sudo apt-get update && apt-get install brltty brlapi-dev
### Credits
Dave Mielke for brltty.

#### bugs known
* load faille if a file is too big.
##### next stape -->
* adding pdf file support.
* create a gbcat for all users.

READ the man for all informations
