# so_long Overview

## Introduction

**so_long** is a small 2D game project designed to introduce you to working with graphical interfaces using the **MiniLibX** library in C. The goal is to create a simple game where a player navigates a map, collects items, and reaches an exit while avoiding obstacles. The project helps you understand how to render images, handle keyboard input, and manage game loops efficiently.

The main objectives of **so_long** are:
- Learn how to use **MiniLibX** for basic graphics rendering.
- Handle user input and update game elements dynamically.
- Manage memory allocation and free resources properly.
- Implement pathfinding and collision detection.
---
## Compilation

```
make
```
Or, if there is no Makefile:
```
gcc -Wall -Wextra -Werror + all files which have .c as extenstion
```
Run the program:
```
./exec_name(check Makefile) + maps/[map_to_test]

```
## Topics Covered

### 1. **MiniLibX Basics**
   - Initializing and setting up a graphical window.
   - Loading and displaying images (textures, sprites).
   - Handling key inputs and events.

### 2. **Map Parsing**
   - Reading a map from a `.ber` file.
   - Validating the map structure (walls, collectibles, exit).
   - Converting the map into a 2D grid representation.

### 3. **Player Movement and Input Handling**
   - Handling keyboard inputs (e.g., `WASD` or arrow keys).
   - Moving the player within the game grid.
   - Preventing movement through walls and ensuring valid moves.

### 4. **Game Mechanics**
   - Implementing collectible items (coins, keys, etc.).
   - Checking for win conditions (player reaches the exit after collecting all items).
   - Adding enemies or obstacles (optional for extra challenge).

### 5. **Rendering and Animation**
   - Updating the screen efficiently on each move.
   - Managing frame rate and animations (optional for smoother movement).
   - Implementing simple sprite changes based on player actions.

### 6. **Pathfinding (Optional)**
   - Ensuring there is a valid path from the start position to the exit.
   - Using algorithms like **Flood Fill** or **Breadth-First Search (BFS)** for path validation.

### 7. **Memory Management**
   - Allocating and freeing dynamically used memory.
   - Preventing memory leaks using `valgrind` or similar tools.
   - Cleaning up resources before program exit.

---

## Why Is This Important?

The **so_long** project introduces you to:
- **Basic graphics programming** using **MiniLibX**.
- **Event-driven programming** by handling user input and screen updates.
- **Game development fundamentals**, such as rendering, input handling, and collision detection.
- **Algorithmic problem-solving** with map parsing and optional pathfinding.
- **Memory management** in a graphical program.

By completing this project, you gain valuable experience in working with event-driven applications and low-level graphics, which are foundational for game development and graphical applications.

---

## Conclusion

**so_long** is a great introduction to 2D game development using **C** and **MiniLibX**. It strengthens your understanding of graphics rendering, user input handling, and game mechanics while reinforcing your memory management skills. Successfully completing this project will give you confidence in working with graphical libraries and event-driven programming.
