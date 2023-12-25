# ReversiBoard_Game

In this exercise you are to implement a board for playing Reversi (https://en.wikipedia.org/wiki/Reversi). (There are several browser based implementations online, e.g. https://cardgames.io/reversi/, that can give you an idea of the game.)

Write a class ReversiBoard that represents the state of the board, i.e. which fields are empty, occupied with a piece with player 1’s color up or occupied with player 2’s color up. Use an enumeration to represent the fields' states. 

The board class must provide a method for querying any field’s state and a method for setting a field’s state, i.e. putting a new piece on the board. This latter method must check that the move is valid (the piece may be put at the given location) and update the state of the board ("turn over" other pieces as required by the rules). 

Write a second class ReversiConsoleView that prints the board on the console. The class receives a pointer to an instance of ReversiBoard as parameter of its constructor. In its print() method, it uses the pointer to obtain the states of the fields and creates the appropriate output.

In your main function, implement a small loop that queries the user where to put the next piece, invokes the method to put the piece on the board and prints the board’s new state. 

Provide hand-written (or hand-drawn) UML class diagrams for your classes.

Don’t forget to provide proper doxygen style documentation as described in the "Organization" section of the Moodle course for this lab. In order to verify your documentation, you must generate a “web-site” from your source code.

Have a look at the uploaded source code from the second lecture in Moodle (lecture course). It includes a file SimpleVector.doxyfile. Copy this file into your project directory and rename it (e.g. to Reversi.doxyfile). Now right-click on your project and select the menu item “@ Build Documentation”. You will see some output from the build process in the console window. When building has finished, there will be a new folder in your project called html. Within this folder, you’ll find a file called index.html. Open it in your browser and you’ll see the generated documentation.

Remember that this documentation is what another programmer reads when he wants to use the classes that you have developed. Therefore the documentation must be comprehensive. Imagine that you wanted to make use of your classes and all you had is this documentation (no source code). Verify that your documentation really includes all required descriptions and hints. If you have problems generating the documentation go to the open labs and ask for help. Remember that the generated documentation must be presented during the review for all tasks from this exercise and all exercises to come.