#Phonebook Project
By Orel Aviad
##Execution
1. Please compile the phonebook program using the below command (you would need gcc compiler): gcc -g phonebook.c -o phonebook

2. You can run the program under valgrind to see that there are no memory leaks (you would need valgrind installed): valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --trace-children=no --show-below-main=yes --num-callers=50 --log-file=phonebook.log ./phonebook

###Description
Phonebook program that demonstrate all capabilities such as : insert a contact, delete a contact, edit a contact, search for a contact. And also sort all of the contacts in the list.

####Data Structure
I've used a linked list for this project because it can be easily allocated in the memory without having to change all of the formation
