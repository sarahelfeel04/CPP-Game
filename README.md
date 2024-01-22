# C++ Game Project

## Overview

Welcome to the C++ Console-Game Project Repository! This project involves creating a simple yet exciting 2D game that merges elements from classic games like Pac-Man and Metal Slug. The mission is to navigate through a 15x15 grid, eliminating all monsters from the game.
Watch the game being played from the consoler [here](https://drive.google.com/drive/u/0/folders/1_0QYzwJpKZICTSgUshSwgooNSeyLYxIj)

## Game Characters

### Hero
- The player-controlled character.
- Armed with a customizable weapon.
- Different hero subclasses with unique abilities:
  - **MedicHero:** Has a healing ability.
  - **DemolitionHero:** Can wield two weapons simultaneously.

### Monsters
- Various monsters roaming the grid, each with distinct characteristics:
  - **GhostMonster:** Can disappear temporarily.
  - **TankMonster:** Has a shield absorbing damage.

## Game Dynamics

### Weapons
- Heroes carry guns with different attributes.
- Gun subclasses: **Pistol:** , **Bazooka:** , **Rifle:** .

### Items
- Ammo: Collectible bullets to replenish the hero's gun.
- Potions: Health-boosting items for the hero.

## Possible Operations

1. **Movement:** Navigate the hero through the grid using 'w', 'a', 's', 'd'.
2. **Shooting:** Use the hero's gun to eliminate monsters in different directions.
3. **Special Abilities:**
   - MedicHero: Heal once during the game.
   - DemolitionHero: Switch between two weapons.

## Win and Lose Scenarios

- **Win:** Eliminate all monsters on the grid.
- **Lose:**
  - Hero's health drops to zero.
  - Hero succumbs to a TankMonster's attack.

## Implementation

- Implement the classes: Object, Character, Hero, Gun, Monster, Item, Game
- Overload operators for display and interactions.
- Implement the methods that will apply the game logic
- Implement hero's special abilities.
- Manage game flow, rounds, and update map dynamically.

