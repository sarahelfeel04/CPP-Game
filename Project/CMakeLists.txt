cmake_minimum_required(VERSION 3.26)
project(Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project main.cpp
        Object.h
        Character.h
        Gun.h
        Hero.h
        Pistol.h
        Bazooka.h
        Rifle.h
        Monster.h
        MedicHero.h
        DemolitionHero.h
        GhostMonster.h
        TankMonster.h
        Item.h
        Ammo.h
        Potion.h
        Game.h)
