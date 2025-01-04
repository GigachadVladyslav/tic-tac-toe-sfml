# Tic Tac Toe Game SFML

This is a simple Tic Tac Toe game created using C++ and SFML (Simple and Fast Multimedia Library). The game features a graphical interface where two players can play Tic Tac Toe on a 3x3 grid. The game includes a main menu, gameplay screen, and a game over screen with options to restart or exit the game.

## Features

- **Main Menu**: Start or exit the game.
- **Gameplay**: Players alternate placing "X" and "O" on the grid.
- **Game Over Screen**: Displays the result of the game (Player X wins, Player O wins, or Draw) with options to restart or exit.
- **Responsive UI**: The game window adjusts its size based on the screen size.

## Dependencies

- **SFML**: This game uses the SFML library for graphics, window management, and user input. You can download SFML from [SFML Official Website](https://www.sfml-dev.org/download.php).

## Installation

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/GigachadVladyslav/tic-tac-toe-sfml.git
   cd tic-tac-toe

Install SFML:

Follow the installation instructions for SFML on your platform:

    Windows: SFML Windows Installation Guide

    Mac: SFML Mac Installation Guide

    Linux: Install SFML using your package manager. For example, on Ubuntu:

Compile the Code:

After installing SFML, compile the C++ code using g++ or your preferred C++ compiler:

g++ -o tic-tac-toe main.cpp -lsfml-graphics -lsfml-window -lsfml-system

Run the Game:

After compiling, you can run the game:

./tic-tac-toe

File Structure

/assets
    /x.png                # Image for Player X
    /o.png                # Image for Player O
    /background.png       # Image for background
/font
    /Parkinsans-Medium.ttf  # Font used for text
/Code
    include.hpp           # Header files for game logic and rendering
    Boardload.cpp          # Class for the Tic Tac Toe board and game logic
    Boardload.hpp
    Button.cpp             # Class for buttons used in the UI
    Button.hpp
    Font.cpp
    Font.hpp
    main.cpp               # Main game logic and window rendering
    WindowRender.cpp
    WindowRender.hpp

/Libaries
    /SFML-2.6.2
      /bin       https://www.sfml-dev.org/tutorials/2.6/start-vc.php
      /include
      /lib


sudo apt-get install libsfml-dev
![image](https://github.com/user-attachments/assets/f43fe279-a82d-4c97-872d-e0cb7e80ab58)
![image](https://github.com/user-attachments/assets/62597ccf-1c11-4205-ac00-fd74246e9e2d)
![image](https://github.com/user-attachments/assets/6a26c000-ba19-4b26-bc66-5bad6de9dcb4)
