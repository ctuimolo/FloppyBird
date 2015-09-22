Fall 2015: CMPM 170, Summer project #3
A "Flappy bird-like" with OOP design focus

Author     : Chaiz Tuimoloau 
Game       : flOppy bird
Language   : C++
Library    : SFML 2.3.1
Development: Microsoft Visual C++ 2010

This project was primarily an exercise in C++ object oriented programming.
Concepts implemented include a room manager system, and universal game object
classes.

==== flOppy bird mechanics ====
- colliding with pipes or floor with result in death
- tap or hold "space" to fly upwards
- As you pass pipes your high score will increase
- pipe layout is persistent and will speed up as relays through level increase
- press Escape at any time to return to title
    

the sprites are home made.

KNOWN BUG:
Upon loading the main level screen after a game over screen, roughly 1/6 times 
the PipeSpawner which controlls the pipe and floor speed might not be getting
properly referenced or called. This will result in a blank screen with just
flOppy bird. Reloading the title screen through the Escape key seems to
return the game to a normal running state for the rest of the time the window
is open.... 